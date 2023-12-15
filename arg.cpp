#include <windows.h>

int main(int argc, wchar_t *argv[])
{
    int numArgs;
    LPWSTR *args = CommandLineToArgvW(GetCommandLineW(), &numArgs);

    if (args)
    {
        wprintf(L"Number of arguments: %d\n", numArgs);

        for (int i = 0; i < numArgs; ++i)
        {
            wprintf(L"Argument %d: %s\n", i, args[i]);
        }

        // Free the allocated memory
        LocalFree(args);
    }

    if (numArgs > 1 && !lstrcmpW(args[1], L"/watchdog"))
        {
            wprintf(L"hi\n");
        }

    return 0;
}
