#ifndef MEMORY_MANAGER
#define MEMORY_MANAGER
#pragma once


#include <stdlib.h>
#include "mem_team.h"

enum e_memory_teams
{
	AI,
	GRAPHICS,
	AUDIO,
	MAX_MEMORY_TEAMS
};

const size_t MEMORY_COUNT_AI = 16 * 1000000;
const size_t MEMORY_COUNT_GRAPHICS = 32 * 1000000;
const size_t MEMORY_COUNT_AUDIO = 0;

const size_t memory_ammounts[e_memory_teams::MAX_MEMORY_TEAMS] =
{
	MEMORY_COUNT_AI,
	MEMORY_COUNT_GRAPHICS,
	MEMORY_COUNT_AUDIO
};

class c_memory_manager
{
	// Circular inclusion was the issue. It is fine to have the enums in this file.
	c_mem_team memory_teams[e_memory_teams::MAX_MEMORY_TEAMS];
	void* global_memory_pool;

public:
	c_memory_manager();
	~c_memory_manager();
	void initialize();
	void shutdown();
};

#endif