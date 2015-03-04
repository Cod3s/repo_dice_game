#include "memory_manager.h"

c_memory_manager::c_memory_manager()
{

}

c_memory_manager::~c_memory_manager()
{
	shutdown();
}

void c_memory_manager::initialize()
{
	// 1028 MB
	global_memory_pool = malloc(1028 * 1000000);
	char* cur_address = (char*)global_memory_pool;

	for (unsigned int index = 0; index < e_memory_teams::MAX_MEMORY_TEAMS; ++index)
	{
		memory_teams[index].assign_memory(cur_address, memory_ammounts[index]);
		cur_address += memory_ammounts[index];
	}

}

void c_memory_manager::shutdown()
{
	if (global_memory_pool != NULL)
	{
		free(global_memory_pool);
		global_memory_pool = NULL;
	}
}
