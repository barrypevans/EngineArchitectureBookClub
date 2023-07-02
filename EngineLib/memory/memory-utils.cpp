#include "memory-utils.h"

uint64_t AlignAddr(uint64_t addr, Alignment alignment)
{
	const uint64_t mask = (uint64_t)alignment - 1;
	assert((alignment & mask) == 0); // enforce pot
	return (addr + mask) & ~mask;
}
