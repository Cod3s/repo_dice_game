//////////////////////////////////////////////////////////////////////
//	File Name	:	"CGame.cpp"
//
//	Author Name	:	Alex Gendron
//
//	Purpose	:	To contain all game code.
//////////////////////////////////////////////////////////////////////
#include "CGame.h"
//#include "CMainMenuState.h"
//#include "COptionsState.h"

#include "game_states/c_main_menu_state.h"

CGame::CGame(void)
{
	m_pD3D	= NULL;
	m_pTM	= NULL;
	m_pDS	= NULL;
	m_pWM	= NULL;
	m_pDI	= NULL;

	m_pState = NULL;

	m_nImageID = -1;
	m_nSoundID = -1;

	m_bFull	= false;

	m_nWidth = 0;
	m_nHeight = 0;

	m_nEffectVol = 0;
	m_nSoundVol = 0;
	m_nPan		= 0;
}

CGame::~CGame(void)
{

}

CGame* CGame::GetInstance(void)
{
	// TODO: Lazy instantiantion:
	static CGame instance;
	return &instance;
}

void CGame::Initialize( HWND hWnd, HINSTANCE hInstance ,int nScreenWidth, int nScreenHeight, bool bIsWindowed)
{
	//	Get pointerrs to singletons
	m_pD3D	= CSGD_Direct3D::GetInstance();
	m_pTM	= CSGD_TextureManager::GetInstance();
	m_pDS	= CSGD_DirectSound::GetInstance();
	m_pWM	= CSGD_WaveManager::GetInstance();
	m_pDI	= CSGD_DirectInput::GetInstance();

	//	Initialize singletons;
	m_pD3D->InitDirect3D(hWnd, nScreenWidth, nScreenHeight, bIsWindowed, true);
	m_pTM->InitTextureManager( m_pD3D->GetDirect3DDevice(), m_pD3D->GetSprite());
	m_pDS->InitDirectSound( hWnd );
	m_pWM->InitWaveManager(hWnd, m_pDS->GetDSObject());
	m_pDI->InitDirectInput(hWnd, hInstance, DI_KEYBOARD | DI_MOUSE);// | DI_MOUSE, DI_MOUSE);

	m_nWidth = nScreenWidth;
	m_nHeight = nScreenHeight;

	//ChangeState(CMainMenuState::GetInstance());
	ChangeState(c_main_menu_state::GetInstance());
	
	m_nEffectVol	 = 5;
	m_nSoundVol		 = 50;
	m_nPan			 = 0;
	//	Load common assets:

	/*m_nImageID = m_pTM->LoadTexture("resource/SGD_Ship.bmp", D3DCOLOR_XRGB(0, 0, 0));
	m_nSoundID = m_pWM->LoadWave("resource/SGD_sfx1.wav");*/
}

bool CGame::Main(void)
{
	if(Input() == false)
		return false;

	Update();

	Render();

	return true;
}


bool CGame::Input(void)
{
	// take a snap shot of input states
	m_pDI->ReadDevices();		//usuall called ONCE a frame

	// quit if the user presses ESC
	if(m_pDI->KeyPressed(DIK_ESCAPE))
	{
		//return false;
	}

	//	Demonstrate the difference between "buffered" (pressed)
	//	and "immediate" (down) AUDIBLY!
	//buffered
	//if(m_pDI->KeyPressed(DIK_1))
	//{
	//	m_pWM->Play(m_nSoundID);
	//}

	//// immediate
	//if(m_pDI->KeyDown(DIK_2))
	//{
	//	m_pWM->Play(m_nSoundID);
	//}

	bool result = m_pState->Input();

	if (result == false)
	{
		return false;
	}

	if( m_pDI->KeyDown(DIK_LALT) || m_pDI->KeyDown(DIK_RALT))			//KeyPressed may work
	{
		if(m_pDI->KeyPressed(DIK_RETURN))
		{
			//TODO: Switch window mode
			//possibly pause
			m_bFull = !m_bFull;
			m_pD3D->ChangeDisplayParam(m_nWidth, m_nHeight, m_bFull);
		}
	}

	

	return true;
}

void CGame::Update(void)
{
	m_pWM->Update();		// cleans up excess copies of sounds
	m_pState->Update();
}

void CGame::Render(void)
{
	m_pD3D->Clear(0,0, 128);
	m_pD3D->DeviceBegin();
	m_pD3D->SpriteBegin();

	// do rendering here
	/*static float fRot = 0.0f;
	fRot += 0.01f;

	m_pTM->Draw(m_nImageID, 100, 100, 4.0f, 2.0f, NULL, 64.0f, 64.0f, fRot, D3DCOLOR_ARGB(128, 255, 0, 0));
*/
	m_pD3D->GetSprite()->Flush();
	//m_pD3D->DrawTextA("Hello World!", 100, 132);

	m_pState->Render();

	m_pD3D->SpriteEnd();
	m_pD3D->DeviceEnd();
	m_pD3D->Present();
}

void CGame::Shutdown(void)
{
	//TODO: Shutdown in the opposite order:
	if( m_pDI)
	{
		m_pDI->ShutdownDirectInput();
		m_pDI = NULL;
	}
	if( m_pWM )
	{
		m_pWM->ShutdownWaveManager();
		m_pWM = NULL;
	}

	if(m_pDS)
	{
		m_pDS->ShutdownDirectSound();
		m_pDS = NULL;
	}

	if( m_pTM )
	{
		m_pTM->ShutdownTextureManager();
		m_pTM = NULL;
	}

	if(m_pD3D )
	{
		m_pD3D->ShutdownDirect3D();
		m_pD3D = NULL;
	}
}

void CGame::ChangeState(IGameState* state)
{
	if(m_pState)
		m_pState->Exit();

	if(state == NULL)
	{
		//TODO: call exit state or something
		PostQuitMessage(0);
		return;
	}
	
	m_pState = state;
	m_pState->Enter();

}