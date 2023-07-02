#pragma once
#include "stack-allocator.h"

class MemoryManager
{
public :
	
	void Init();
	void Update();
	void ShutDown();

	StackAllocator* GetSystemAllocator() { return &m_systemAllocator; }

private:
	StackAllocator m_systemAllocator;
};

