//////////////////////////////////////////////////////////////////////
//	File Name	:	"CGame.h"
//
//	Author Name	:	Alex Gendron
//
//	Purpose	:	To contain all game code.
//////////////////////////////////////////////////////////////////////
//#pragma once	// MSVStudio specific

//	Cross- compiler compatible
#ifndef	CGAME_H_
#define CGAME_H_

//	SGD singletons:
#include "SGD Wrappers/CSGD_Direct3D.h"
#include "SGD Wrappers/CSGD_TextureManager.h"
#include "SGD Wrappers/CSGD_DirectSound.h"
#include "SGD Wrappers/CSGD_WaveManager.h"
#include "SGD Wrappers/CSGD_DirectInput.h"

#include "IGameState.h"


class CGame
{
private:
	// Singleton pointers:
	CSGD_Direct3D*			m_pD3D;
	CSGD_TextureManager*	m_pTM;
	CSGD_DirectSound*		m_pDS;
	CSGD_WaveManager*		m_pWM;
	CSGD_DirectInput*		m_pDI;

	IGameState*				m_pState;

	//	Asset ids:
	int						m_nImageID;
	int						m_nSoundID;

	bool					m_bFull;
	int						m_nWidth;
	int						m_nHeight;

	int						m_nEffectVol;
	int						m_nSoundVol;
	int						m_nPan;


	// Proper singleton:
	//	Constructor
	CGame(void);
	//	Trilogy of EVIL!
	//		copy constructor
	CGame(const CGame&);
	//		Assignment operator
	CGame& operator=(const CGame&);
	//		Destructor
	~CGame(void);

	//	Utility functions:
	//	returns false if game should quit
	bool Input(void);
	void Update(void);
	void Render(void);

public:
	//	Singleton accessor
	static CGame* GetInstance(void);

	void ChangeState(IGameState* state);

	//	3 steps a game goes throug in it's lifetime
	//	1. Initialization
	void Initialize( HWND hWnd, HINSTANCE hInstance ,int nScreenWidth, int nScreenHeight, bool bIsWindowed);
	//	2. Execution
	//	returns false when game should quit
	bool Main(void);
	//	3. Clean Up
	void Shutdown(void);

	void SetEffectVol(int vol){ m_nEffectVol = vol;};
	void SetSoundVol(int vol){ m_nSoundVol = vol;};
	void SetPan(int pan){ m_nPan = pan;};
	int GetEffectVol(){ return m_nEffectVol;};
	int GetSoundVol(){ return m_nSoundVol;};
	int GetPan() {return m_nPan;};
};

#endif