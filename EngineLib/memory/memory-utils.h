#pragma once

#include <assert.h>
#include <cstdint>

#define KiB(x) (uint64_t)x * (uint64_t)0x400
#define MiB(x) (uint64_t)x * (uint64_t)0x100000
#define GiB(x) (uint64_t)x * (uint64_t)0x40000000

enum Alignment : uint32_t
{
	kAlign_4byte = 0x04,
	kAlign_8byte = 0x08,
	kAlign_16byte = 0x10
};

template<typename T>
T* AlignPtr(T* pPtr, Alignment alignment)
{
	const uint64_t mask = (uint64_t)alignment - 1;
	assert((alignment & mask) == 0); // enforce pot
	uint64_t address = reinterpret_cast<uint64_t>(pPtr);
	return reinterpret_cast<T*>((address + mask) & ~mask);
}

uint64_t AlignAddr(uint64_t addr, Alignment alignment);