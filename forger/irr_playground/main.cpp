#include <irrlicht.h>
using namespace irr;
using namespace core;

#include <stdlib.h>

#include <string>
#include <windows.h>


int main()
{
	// start up the engine
	IrrlichtDevice *device = createDevice(video::EDT_DIRECT3D9,
		core::dimension2d<u32>(640, 480), 32, false, false, true);

	if (!device)
	{
		return 1;
	}

	video::IVideoDriver* driver = device->getVideoDriver();
	scene::ISceneManager* scenemgr = device->getSceneManager();
	gui::IGUIEnvironment* guienv = device->getGUIEnvironment();
	

	guienv->addStaticText(L"Hello World! This is the Irrlicht Software renderer!",
		rect<s32>(10, 10, 260, 42), true);
	

	device->setWindowCaption(L"Hello World!");

	// load and show quake2 .md2 model
	//scene::ISceneNode* node = scenemgr->addAnimatedMeshSceneNode(
	//	scenemgr->getMesh("quake2model.md2"));



	// if everything worked, add a texture and disable lighting
	//if (node)
	/*{
		node->setMaterialTexture(0, driver->getTexture("texture.bmp"));
		node->setMaterialFlag(video::EMF_LIGHTING, false);
	}*/


	scene::IAnimatedMesh* mesh = scenemgr->getMesh("sydney.md2");
	if (!mesh)
	{
		device->drop();
		return 1;
	}

	scene::IAnimatedMeshSceneNode* node = scenemgr->addAnimatedMeshSceneNode(mesh);

	if (node)
	{
		node->setMaterialFlag(video::EMF_LIGHTING, false);
		node->setMD2Animation(scene::EMAT_STAND);
		node->setMaterialTexture(0, driver->getTexture("sydney.bmp"));
		node->setRotation(vector3df(0.0f, 90.0f, 0.0f));
	}

	// add a first person shooter style user controlled camera
	//scenemgr->addCameraSceneNodeFPS();

	scenemgr->addCameraSceneNode(0, vector3df(0, 30, -40), vector3df(0, 5, 0));
	f32 current_rotation = 15.0f;
	// draw everything
	ITimer* timer = device->getTimer();
	u32 previous_time = timer->getRealTime();
	while (device->run() && driver)
	{
		u32 start_time = timer->getRealTime();

		f32 delta_time = (start_time - previous_time) / 1000.0f;

		if (delta_time > 0.1f)
		{
			delta_time = 0.1f;
		}

		previous_time = start_time;
		
		current_rotation += current_rotation * delta_time * 1.5f;

		if (current_rotation > 360.0f)
		{
			current_rotation = 15.0f;
		}

		node->setRotation(vector3df(0.0f, current_rotation, 0.0f));
		driver->beginScene(true, true, video::SColor(255, 0, 0, 255));
		scenemgr->drawAll();
		guienv->drawAll();
		driver->endScene();
	}

	// delete device
	device->drop();
	return 0;
}