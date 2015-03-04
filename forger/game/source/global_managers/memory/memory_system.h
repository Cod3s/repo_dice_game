#ifndef MEMORY_SYSTEM
#define MEMORY_SYSTEM
#pragma once

#include "mem_team.h"
#include "memory_manager.h"

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

const size_t memory_ammounts[MAX_MEMORY_TEAMS] = 
{
	MEMORY_COUNT_AI,
	MEMORY_COUNT_GRAPHICS,
	MEMORY_COUNT_AUDIO
};

#endif // MEMORY_SYSTEM