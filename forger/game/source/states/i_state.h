#ifndef I_STATE
#define I_STATE
#pragma once

#include "..\global_managers\sf_manager.h"

class i_state
{
protected:
	c_sf_manager* h_manager;

	i_state(c_sf_manager* manager)
	{
		if (manager != nullptr)
		{
			h_manager = manager;
		}
	}

public:
	virtual void initialize() = 0;
	virtual void input() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
	virtual void shutdown() = 0;
};


#endif // I_STATE