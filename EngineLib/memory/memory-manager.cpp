#include "memory-manager.h"
#include "memory-utils.h"

MemoryManager g_memoryManager;

void MemoryManager::Init()
{
	m_systemAllocator.Init(GiB(8)); // 10 gb of system memory
}

void MemoryManager::Update()
{
}

void MemoryManager::ShutDown()
{
	m_systemAllocator.Shutdown();
}
