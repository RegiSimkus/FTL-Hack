#pragma once
#include <Windows.h>

class Game
{
public:
	uintptr_t ShipAddress;

	uintptr_t GetShip();
	void SetHealth(int Health);

	void SetMaxHealth(int MaxHealth);
	int GetMaxHealth();
	
	int GetScrap();
	void SetScrap(int Scrap);

	uintptr_t GetEnemy();
	void KillEnemy();
};

extern Game* g_Game;