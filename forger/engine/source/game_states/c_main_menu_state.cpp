#include "c_main_menu_state.h"

c_main_menu_state* c_main_menu_state::GetInstance(void)
{
	static c_main_menu_state state;
	return &state;
}

void c_main_menu_state::Enter(void)
{
	m_d3d = CSGD_Direct3D::GetInstance();
	m_input = CSGD_DirectInput::GetInstance();
}

bool c_main_menu_state::Input(void)
{
	if (m_input->KeyPressed(DIK_ESCAPE))
	{
		return false;
	}

	return true;
}

void c_main_menu_state::Update(void)
{
	
}

void c_main_menu_state::Render(void)
{
	m_d3d->DrawTextA("Hello world!", m_input->MouseGetPosX(), m_input->MouseGetPosY(), 255, 0, 0);
	
}

void c_main_menu_state::Exit(void)
{

}

c_main_menu_state::c_main_menu_state(void)
{
	m_d3d = NULL;
	m_input = NULL;
}

c_main_menu_state::~c_main_menu_state(void)
{
}

c_main_menu_state::c_main_menu_state(const c_main_menu_state &)
{
}

c_main_menu_state & c_main_menu_state::operator=(const c_main_menu_state &)
{
	return *this;
}
