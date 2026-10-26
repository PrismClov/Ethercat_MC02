"""读取 ecat_live.exe 发布的 IMU 共享内存并跑 Mahony 姿态解算。

先启动 ecat_live.exe，然后运行:  python mahony_reader.py
"""
import mmap
import struct
import time

SHM_NAME = "ecat_imu"
SIZE = 60
FMT = "<IIQ3f3f3h3hHHHH"     # 与 imu_shm.h 一一对应

q = [1.0, 0.0, 0.0, 0.0]     # w x y z
e_int = [0.0, 0.0, 0.0]


def mahony(q, gyro, acc, dt, kp=2.0, ki=0.02):
    ax, ay, az = acc
    n = (ax * ax + ay * ay + az * az) ** 0.5
    if n < 1e-6:
        return
    ax, ay, az = ax / n, ay / n, az / n

    qw, qx, qy, qz = q
    # 估计重力方向
    vx = 2.0 * (qx * qz - qw * qy)
    vy = 2.0 * (qw * qx + qy * qz)
    vz = qw * qw - qx * qx - qy * qy + qz * qz

    ex = ay * vz - az * vy
    ey = az * vx - ax * vz
    ez = ax * vy - ay * vx

    if ki > 0.0:
        e_int[0] += ex * dt
        e_int[1] += ey * dt
        e_int[2] += ez * dt

    gx, gy, gz = gyro
    gx += kp * ex + ki * e_int[0]
    gy += kp * ey + ki * e_int[1]
    gz += kp * ez + ki * e_int[2]

    # 一阶积分
    h = 0.5 * dt
    qw, qx, qy, qz = q
    q[0] += (-qx * gx - qy * gy - qz * gz) * h
    q[1] += ( qw * gx + qy * gz - qz * gy) * h
    q[2] += ( qw * gy - qx * gz + qz * gx) * h
    q[3] += ( qw * gz + qx * gy - qy * gx) * h

    n = sum(c * c for c in q) ** 0.5
    for i in range(4):
        q[i] /= n


def euler(q):
    w, x, y, z = q
    roll = __import__("math").atan2(2 * (w * x + y * z), 1 - 2 * (x * x + y * y))
    s = max(-1.0, min(1.0, 2 * (w * y - z * x)))
    pitch = __import__("math").asin(s)
    yaw = __import__("math").atan2(2 * (w * z + x * y), 1 - 2 * (y * y + z * z))
    return roll, pitch, yaw


def open_shm():
    for _ in range(50):
        try:
            return mmap.mmap(-1, SIZE, tagname=SHM_NAME)
        except OSError:
            time.sleep(0.1)
    raise SystemExit("打不开共享内存 %s，先启动 ecat_live.exe" % SHM_NAME)


def main():
    m = open_shm()
    last_seq = 0
    last_t = None
    n = 0
    t_print = time.time()

    while True:
        s1 = struct.unpack_from("<I", m, 0)[0]
        d = struct.unpack_from(FMT, m, 0)
        s2 = struct.unpack_from("<I", m, 0)[0]
        if s1 != s2 or (s1 & 1) or s1 == last_seq:
            continue
        last_seq = s1
        _, magic, t_us, ax, ay, az, gx, gy, gz, *_rest = d
        if magic != 0x314D5531:
            continue

        t = t_us * 1e-6
        if last_t is not None:
            dt = t - last_t
            if 0 < dt < 0.1:
                mahony(q, (gx, gy, gz), (ax, ay, az), dt)
        last_t = t

        n += 1
        if time.time() - t_print > 0.2:
            r, p, y = euler(q)
            print("\r%6.1f Hz  acc=(%5.2f,%5.2f,%5.2f)m/s2  gyro=(%6.3f,%6.3f,%6.3f)rad/s  "
                  "RPY=(%7.1f,%7.1f,%7.1f)deg"
                  % (n / (time.time() - t_print), ax, ay, az, gx, gy, gz,
                     r * 57.2958, p * 57.2958, y * 57.2958), end="")
            n = 0
            t_print = time.time()


if __name__ == "__main__":
    main()
