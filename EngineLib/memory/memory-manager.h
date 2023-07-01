#pragma once

#include "../engine-subsystem.h"
#include "stack-allocator.h"

class MemoryManager : public EngineSubsystem
{
public :
	// Inherited via EngineSubsystem
	virtual void Init() override;
	virtual void Update() override;
	virtual void ShutDown() override;

	StackAllocator* GetSystemAllocator() { return &m_systemAllocator; }

private:
	StackAllocator m_systemAllocator;
};

