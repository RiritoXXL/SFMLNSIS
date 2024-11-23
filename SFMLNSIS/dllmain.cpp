// dllmain.cpp : Defines the entry point for the DLL application.
#include "includes.hpp"
#include <SFML/Audio.hpp>
#include <pluginapi.h>
#define STATUS_SUCCESS 1
#define EXITFAILED 5300
#pragma comment(lib, "legacy_stdio_definitions.lib")
bool isinitalizated = true;
HINSTANCE g_hInstance;
HWND g_hwndParent;
extern "C" void __declspec(dllexport) PlayMusicWithLoop(HWND hwndParent, int string_size, LPTSTR variables, stack_t** stacktop, const char* mus_filename)
{
    EXDLL_INIT();
    sf::Music mus;
    if (mus.openFromFile(mus_filename)) {
        mus.setLoop(true);
        mus.play();
    }
    else 
    {
        MessageBoxA(0, "Failed!!!", "SFMLNSIS", MB_OK | MB_ICONERROR);
        ExitProcess(1223);
    }
}
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

