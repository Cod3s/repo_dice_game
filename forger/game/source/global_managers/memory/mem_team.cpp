#include "mem_team.h"

c_mem_team::c_mem_team()
{

}

c_mem_team::c_mem_team(char _id)
{
	id = _id;
}

c_mem_team::~c_mem_team()
{

}

void c_mem_team::assign_memory(void* mem_addr, size_t _mem_size)
{
	memory = mem_addr;
	mem_size = _mem_size;
}