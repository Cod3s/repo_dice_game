#ifndef MEMORY_MANAGER
#define MEMORY_MANAGER
#pragma once


#include <stdlib.h>
#include "memory_system.h"

class c_memory_manager
{
	// figure out why system enum doesn't work
	c_mem_team memory_teams[e_memory_teams::MAX_MEMORY_TEAMS];
	void* global_memory_pool;

public:
	c_memory_manager();
	~c_memory_manager();
	void initialize();
	void shutdown();
};

#endif