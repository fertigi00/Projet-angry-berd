#pragma once
#include "raylib.h"
class cameraManager
{
public:
	cameraManager();
	void update(InputController..InpuytSnapshot& inputs, float duration);
	Camera3D GetCamera();

private: 
	ICameraController* m_currentCamera;

};

