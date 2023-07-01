#pragma once
#include <cstdint>

class StackAllocator
{
public:
	StackAllocator();
	~StackAllocator();
	void Init(size_t stackSize);
	void Shutdown();
	void* Alloc(size_t bytes);
	void FreeLastBlock();

	size_t GetCurStackSize();

private:

	size_t GetCurrentMarker();
	size_t m_maxStackSize;

	static const uint32_t kMaxAllocations = 256;
	size_t m_markerList[kMaxAllocations];
	uint32_t m_curMarkerIndex;

	char* m_pMemory;
};