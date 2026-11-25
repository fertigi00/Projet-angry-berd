#pragma once
#include "raylib.h"
#include "InputController.h"
#include "ICameraController.h"
class cameraManager
{
public:
	cameraManager();
	void update(InputController::InputSnapshot& inputs, float duration);
	Camera3D getCamera();

private: 
	ICameraController* m_currentCamera;

};

