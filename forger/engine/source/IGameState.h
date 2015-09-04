//////////////////////////////////////////////////////////////////////
//	File Name	:	"IGameState.h"
//
//	Author Name	:	Alex Gendron
//
//	Purpose	:	Base class for different states
//////////////////////////////////////////////////////////////////////
#ifndef IGAMESTATE_H_
#define IGAMESTATE_H_

class IGameState
{
public:
	virtual ~IGameState(){};
	virtual void Enter(void) = 0;
	virtual bool Input(void) = 0;
	virtual void Update(void) = 0;
	virtual void Render(void) = 0;
	virtual void Exit(void) = 0;

};


#endif