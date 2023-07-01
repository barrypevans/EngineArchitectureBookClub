#include "game.h"
#include "../EngineLib/memory/memory-manager.h"
#include <memory>

extern MemoryManager g_memoryManager;

void Game::Init()
{
	g_memoryManager.Init();
}

void Game::Loop()
{
	while (true)
	{
		g_memoryManager.Update();

		char* pString = (char*)g_memoryManager.GetSystemAllocator()->Alloc(13);
		memcpy(pString, "hello world\n", 13);
		printf(pString);
		g_memoryManager.GetSystemAllocator()->FreeLastBlock();
	}
}

void Game::ShutDown()
{
	g_memoryManager.ShutDown();
}
