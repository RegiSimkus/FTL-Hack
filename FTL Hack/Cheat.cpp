#include "pch.h"
#include <Windows.h>
#include "Cheat.h"
#include "offsets.h"
//class Game
//{
//	uintptr_t ShipAddress;
//
//	uintptr_t GetShip();
//	void SetHealth();
//	void SetMaxHealth();
//	void SetScrap();
//};

uintptr_t Game::GetShip()
{
	DWORD moduleBase = (DWORD)GetModuleHandleA(Offsets::ModuleBase);
	return *(uintptr_t*)(moduleBase + Offsets::Ship);
}

void Game::SetScrap(int Scrap)
{
	*(int*)(GetShip() + Offsets::Scrap) = Scrap;
}

int Game::GetScrap()
{
	return *(int*)(GetShip() + Offsets::Scrap);
}

void Game::SetHealth(int Health)
{
	*(int*)(GetShip() + Offsets::Health) = Health;
}

uintptr_t Game::GetEnemy() // Returns garbage, i have shit offsets
{
	DWORD moduleBase = (DWORD)GetModuleHandle(Offsets::ModuleBase);
	uintptr_t Ship = *(uintptr_t*)((moduleBase + Offsets::Enemy::ShipBase) + Offsets::Enemy::Ship);
	return Ship;
}

void Game::KillEnemy()
{
	uintptr_t Enemy = GetEnemy();
	if (Enemy)
	{
		*(int*)(GetEnemy() + Offsets::Health) = -1;
	}
}

int Game::GetMaxHealth()
{
	return *(int*)(GetShip() + Offsets::MaxHealth);
}

void Game::SetMaxHealth(int MaxHealth)
{
	*(int*)(GetShip() + Offsets::MaxHealth) = MaxHealth;
}