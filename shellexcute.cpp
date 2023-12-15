#include <windows.h>
#include <iostream>

//gcc -o shellexcute shellexcute.cpp -lstdc++

int main() {
    // Specify the wide character string
    const wchar_t* wideFileName = L"notepad.exe";

    // Convert the wide character string to a narrow character string
    int bufferSize = WideCharToMultiByte(CP_UTF8, 0, wideFileName, -1, NULL, 0, NULL, NULL);
    char narrowFileName[260];  // Adjust the size as needed // need to change to LPSTR
    WideCharToMultiByte(CP_UTF8, 0, wideFileName, -1, narrowFileName, bufferSize, NULL, NULL);

    // Initialize the ShellExecuteInfo structure
    SHELLEXECUTEINFO shExecuteInfo = {0};
    shExecuteInfo.cbSize = sizeof(SHELLEXECUTEINFO);
    shExecuteInfo.fMask = SEE_MASK_NOCLOSEPROCESS;  // Keep the process handle for later use
    shExecuteInfo.lpFile = narrowFileName;           // Use narrow character string
    shExecuteInfo.nShow = SW_SHOWNORMAL;             // Show the window normally
    // shExecuteInfo.lpParameters = L"\\test.txt";        // Specify the parameters

    // Execute the application or open the file
    if (ShellExecuteEx(&shExecuteInfo)) {
        // The application or file was successfully launched

        // Optionally, wait for the process to finish
        WaitForSingleObject(shExecuteInfo.hProcess, INFINITE);

        // Close the process handle
        CloseHandle(shExecuteInfo.hProcess);
    } else {
        // Handle the error (check GetLastError() for details)
        DWORD error = GetLastError();
        // Output error information, or perform other error handling
        // For example, you can use FormatMessage to get a human-readable error message
        LPVOID errorMessage;
        FormatMessageA(
            FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
            NULL,
            error,
            0, // Default language
            (LPSTR)&errorMessage,
            0,
            NULL
        );
        printf("Error: %s\n", errorMessage);
        LocalFree(errorMessage);
    }

    return 0;
}
