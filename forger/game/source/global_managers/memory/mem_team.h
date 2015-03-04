#ifndef MEM_TEAM
#define MEM_TEAM
#pragma once

class c_mem_team
{
	char id;
	void* memory;
	size_t mem_size;

public:
	c_mem_team();
	c_mem_team(char _id);
	~c_mem_team();
	void assign_memory(void* mem_addr, size_t _mem_size);

};

#endif // MEM_TEAM