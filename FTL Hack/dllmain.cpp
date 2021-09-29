// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <Windows.h>
#include "Cheat.h"
#include <iostream>

Game* g_Game = new Game();

// godmode stuff
bool godMode = false;
int godMaxHP = 30;

BOOL WINAPI MainThread(HMODULE hModule)
{

    AllocConsole();
    FILE* f;
    freopen_s(&f, "CONOUT$", "w", stdout);
    freopen_s(&f, "CONOUT$", "r", stdin);

    uintptr_t Ship = g_Game->GetShip();
    std::cout << "Ship Address: " << Ship << "\n";

    while (!(GetAsyncKeyState(VK_END)))
    {
        if (false && GetAsyncKeyState(VK_F1) & 1) // 'false &&' because this part will crash your game, i'll fix it later
        {
            std::cout << "Killed enemy.\n";
            g_Game->KillEnemy();
        }

        if (GetAsyncKeyState(VK_F2) & 1)
        {
            std::cout << "Added 1000 scrap\n";
            g_Game->SetScrap(g_Game->GetScrap() + 1000);
        }

        if (GetAsyncKeyState(VK_F3) & 1)
        {
            std::cout << "Reset health\n";
            g_Game->SetHealth(g_Game->GetMaxHealth());
        }

        if (GetAsyncKeyState(VK_F8) & 1)
        {
            if (!godMode)
            {
                godMode = true;
                godMaxHP = g_Game->GetMaxHealth();

                std::cout << "God mode enabled.\n";
                g_Game->SetMaxHealth(20000);
                g_Game->SetHealth(20000);
            }
            else
            {   
                g_Game->SetMaxHealth(godMaxHP);
                g_Game->SetHealth(godMaxHP);
                godMode = false;

                std::cout << "God mode disabled. Your max hp was restored. Your Health was replenished.\n";
            }
        }

        Sleep(5);
    }

    if (f) fclose(f);
    FreeConsole();
    FreeLibraryAndExitThread(hModule, 1);
    return TRUE;
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)MainThread, 0, 0, 0);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

