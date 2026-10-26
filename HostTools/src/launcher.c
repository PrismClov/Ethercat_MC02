/* EcatUI.exe —— 原生启动器
 * 双击后找到同目录下的 ui\ecat_ui.py，用 pythonw 无控制台启动。
 * 默认 Python: D:\clover\Environment\Python\pythonw.exe
 * 可用环境变量 ECAT_PYTHON 覆盖（指向 pythonw.exe）。
 */
#include <windows.h>
#include <wchar.h>

#ifndef APP_TITLE
#define APP_TITLE L"EcatUI"
#endif
#ifndef APP_SCRIPT
#define APP_SCRIPT L"ui\\ecat_ui.py"
#endif

static void die(const wchar_t *msg)
{
    MessageBoxW(NULL, msg, APP_TITLE, MB_ICONERROR | MB_OK);
}

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrev, LPSTR lpCmd, int nShow)
{
    wchar_t exe[MAX_PATH];
    wchar_t root[MAX_PATH];
    wchar_t py[MAX_PATH];
    wchar_t script[MAX_PATH];
    wchar_t cmdline[MAX_PATH * 3];
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

    swprintf(script, MAX_PATH, L"%s\\" APP_SCRIPT, root);
    if (GetFileAttributesW(script) == INVALID_FILE_ATTRIBUTES)
    {
        die(L"找不到 " APP_SCRIPT L"。\n请把 " APP_TITLE L".exe 放在 HostTools 目录下运行。");
        return 1;
    }

    swprintf(cmdline, MAX_PATH * 3, L"\"%s\" \"%s\"", py, script);

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    if (!CreateProcessW(py, cmdline, NULL, NULL, FALSE,
                        CREATE_NO_WINDOW, NULL, root, &si, &pi))
    {
        die(L"启动失败：无法创建 pythonw 进程。");
        return 1;
    }

    CloseHandle(pi.hThread);
    CloseHandle(pi.hProcess);
    return 0;
}
