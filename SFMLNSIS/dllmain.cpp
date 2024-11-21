// dllmain.cpp : Defines the entry point for the DLL application.
#include "includes.hpp"
#include <SFML/Audio.hpp>
#include <pluginapi.h>

void __declspec(dllexport) PlayMusicWithLoop(LPCSTR mus_filename) {
    sf::Music mus;
    if (mus.openFromFile(mus_filename)) {
        mus.setLoop(true);
        mus.play();
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
        MessageBoxA(0, "This is My First Library for SFML(NSIS Programming Language for Windows Installer)... \nSo Enjoy to use this", "SFMLNSIS", MB_OK | MB_ICONINFORMATION);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

