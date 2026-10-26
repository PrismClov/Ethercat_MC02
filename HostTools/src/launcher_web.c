/* EcatWeb.exe —— Web 版启动器
 * 1) 用 pythonw 起 webui\serve.py（默认 8766，静态目录 webui-react\dist）
 * 2) 等 0.8 s 后打开默认浏览器
 * 默认 Python: D:\clover\Environment\Python\pythonw.exe
 * 可用环境变量 ECAT_PYTHON 覆盖。
 */
#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#include <wchar.h>
#include <shellapi.h>

#define PORT L"8766"
#define URL  L"http://127.0.0.1:8766/"

static void die(const wchar_t *msg)
{
    MessageBoxW(NULL, msg, L"EcatWeb", MB_ICONERROR | MB_OK);
}

/* 8766 已经有人监听？双击第二次时不要再起一个桥 */
static int port_open(void)
{
    WSADATA w;
    SOCKET s;
    struct sockaddr_in a;
    int ok = 0;

    if (WSAStartup(MAKEWORD(2, 2), &w) != 0)
        return 0;

    s = socket(AF_INET, SOCK_STREAM, 0);
    if (s != INVALID_SOCKET)
    {
        ZeroMemory(&a, sizeof(a));
        a.sin_family = AF_INET;
        a.sin_port = htons(8766);
        a.sin_addr.s_addr = inet_addr("127.0.0.1");
        if (connect(s, (struct sockaddr *)&a, sizeof(a)) == 0)
            ok = 1;
        closesocket(s);
    }
    WSACleanup();
    return ok;
}

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrev, LPSTR lpCmd, int nShow)
{
    wchar_t exe[MAX_PATH];
    wchar_t root[MAX_PATH];
    wchar_t py[MAX_PATH];
    wchar_t serve[MAX_PATH];
    wchar_t dist[MAX_PATH];
    wchar_t cmdline[MAX_PATH * 4];
    wchar_t *slash;
    DWORD n;
    STARTUPINFOW si;
    PROCESS_INFORMATION pi;

    (void)hInst; (void)hPrev; (void)lpCmd; (void)nShow;

    if (!GetModuleFileNameW(NULL, exe, MAX_PATH))
    {
        die(L"无法获取自身路径。");
        return 1;
    }
    wcscpy(root, exe);
    slash = wcsrchr(root, L'\\');
    if (slash) *slash = 0;

    n = GetEnvironmentVariableW(L"ECAT_PYTHON", py, MAX_PATH);
    if (n == 0 || n >= MAX_PATH)
        wcscpy(py, L"D:\\clover\\Environment\\Python\\pythonw.exe");

    if (GetFileAttributesW(py) == INVALID_FILE_ATTRIBUTES)
    {
        die(L"找不到 pythonw.exe。\n\n请安装 Python 并设置环境变量 ECAT_PYTHON 指向 pythonw.exe。");
        return 1;
    }

    swprintf(serve, MAX_PATH, L"%s\\webui\\serve.py", root);
    swprintf(dist,  MAX_PATH, L"%s\\webui-react\\dist", root);

    if (GetFileAttributesW(serve) == INVALID_FILE_ATTRIBUTES)
    {
        die(L"找不到 webui\\serve.py。\n请把 EcatWeb.exe 放在 HostTools 目录下运行。");
        return 1;
    }
    if (GetFileAttributesW(dist) == INVALID_FILE_ATTRIBUTES)
    {
        die(L"还没有构建产物 webui-react\\dist。\n\n请先运行 build_react.cmd。");
        return 1;
    }

    if (port_open())
    {
        ShellExecuteW(NULL, L"open", URL, NULL, NULL, SW_SHOWNORMAL);
        return 0;
    }

    swprintf(cmdline, MAX_PATH * 4,
             L"\"%s\" \"%s\" --port %s --root \"%s\"", py, serve, PORT, dist);

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    if (!CreateProcessW(py, cmdline, NULL, NULL, FALSE,
                        CREATE_NO_WINDOW, NULL, root, &si, &pi))
    {
        die(L"启动失败：无法创建 serve.py 进程。");
        return 1;
    }
    CloseHandle(pi.hThread);
    CloseHandle(pi.hProcess);

    Sleep(800);   /* 等桥起来再开浏览器 */
    ShellExecuteW(NULL, L"open", URL, NULL, NULL, SW_SHOWNORMAL);
    return 0;
}
