#include "stack-allocator.h"
#include <assert.h>
#include <memory>

#ifdef _WIN32
#include <windows.h>
#include <memoryapi.h>
#endif

StackAllocator::StackAllocator(){}

StackAllocator::~StackAllocator(){}

void StackAllocator::Init(size_t stackSize)
{
	m_maxStackSize = stackSize;
	m_curMarkerIndex = 0;
	
	memset(&m_markerList, 0, sizeof(size_t) * kMaxAllocations);
#ifdef _WIN32
	m_pMemory = (char*)VirtualAlloc(nullptr, stackSize, MEM_COMMIT, PAGE_READWRITE);
#endif
}

void StackAllocator::Shutdown()
{
#ifdef _WIN32
	VirtualFree(m_pMemory, m_maxStackSize, MEM_RELEASE);
#endif
}

void* StackAllocator::Alloc(size_t bytes)
{
	if (GetCurrentMarker() + bytes >= m_maxStackSize) // Out of memory
		return nullptr;

	size_t lastMarker = GetCurrentMarker();

	m_markerList[m_curMarkerIndex] = lastMarker + bytes;
	m_curMarkerIndex++;

	return m_pMemory + GetCurrentMarker();
}

void StackAllocator::FreeLastBlock()
{
	if (m_curMarkerIndex == 0)
		return;

	m_curMarkerIndex--;
}

size_t StackAllocator::GetCurStackSize()
{
	return GetCurrentMarker();
}

size_t StackAllocator::GetCurrentMarker()
{
	if (m_curMarkerIndex == 0)
		return 0;

	return m_markerList[m_curMarkerIndex-1];
}
