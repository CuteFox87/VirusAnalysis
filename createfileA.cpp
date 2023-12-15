#include <windows.h>
#include <stdio.h>

int main() {
    CreateDirectoryA("\\happy", NULL);
    HANDLE hFile = CreateFileA("\\happy\\note.txt", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

    if (hFile == INVALID_HANDLE_VALUE) {
        //puts("bye");
        ExitProcess(4u);
    }

    const char* data = "YOUR COMPUTER HAS BEEN FUCKED BY THE MEMZ TROJAN.\r\n"
                       "\r\n"
                       "Your computer won't boot up again,\r\n"
                       "so use it as long as you can!\r\n"
                       "\r\n"
                       ":D\r\n"
                       "\r\n"
                       "Trying to kill MEMZ will cause your system to be\r\n"
                       "destroyed instantly, so don't try it :D";

    DWORD numberOfBytesWritten;
    if (!WriteFile(hFile, data, strlen(data), &numberOfBytesWritten, NULL)) {
        CloseHandle(hFile);
        ExitProcess(5u);
    }

    CloseHandle(hFile);

    ShellExecuteA(NULL, NULL, "notepad", "\\happy\\note.txt", NULL, SW_SHOWNORMAL); // create in current disk root

    return 0;
}
