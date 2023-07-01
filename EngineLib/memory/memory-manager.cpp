#include "memory-manager.h"

MemoryManager g_memoryManager;

void MemoryManager::Init()
{
	m_systemAllocator.Init(10000000000); // 10 gb of system memory
}

void MemoryManager::Update()
{
}

void MemoryManager::ShutDown()
{
	m_systemAllocator.Shutdown();
}
