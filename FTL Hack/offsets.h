#pragma once
#include <Windows.h>

namespace Offsets
{
	const char* ModuleBase = "FTLGame.exe";

	// Enemy
	// The offsets are no good
	namespace Enemy
	{
		uintptr_t ShipBase = 0x30FF84;
		uintptr_t Ship = 0x7C;
		uintptr_t Health = 0xCC;
	}

	// Us/LocalPlayer
	uintptr_t Ship = 0x51348C;
	uintptr_t Scrap = 0x4D4;
	uintptr_t Health = 0xCC;
	uintptr_t MaxHealth = 0xD0;
}
