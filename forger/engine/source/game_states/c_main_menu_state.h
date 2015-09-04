#ifndef __C_MAIN_MENU_STATE__
#define __C_MAIN_MENU_STATE__
#pragma once

#include "..\IGameState.h"
#include "..\SGD Wrappers\CSGD_Direct3D.h"
#include "..\SGD Wrappers\CSGD_DirectInput.h"


class c_main_menu_state : public IGameState
{
public:

	static c_main_menu_state* GetInstance(void);

	void Enter(void);
	bool Input(void);
	void Update(void);
	void Render(void);
	void Exit(void);

private:

	CSGD_Direct3D* m_d3d;
	CSGD_DirectInput* m_input;

	c_main_menu_state(void);
	~c_main_menu_state(void);
	c_main_menu_state(const c_main_menu_state&);
	c_main_menu_state& operator=(const c_main_menu_state&);

};

#endif // __C_MAIN_MENU_STATE__
