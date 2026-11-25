#include "pch.h"
#include "caméra.h"

cameraManager::cameraManager()
{
}

void cameraManager::update(InputController::InputSnapshot& inputs, float duration)
{
	if (input.key_d)
		m_position.x += 0.5;
}

Camera3D cameraManager::getCamera()
{
	Camera3D camera = { 0 };
	camera.position = m_position;
	camera.target = { 0.0f, 0.0f, 0.0f };
	camera.up = { 0.0f, 0.0f, 0.0f };
	camera.fovy = 45.0f;
	camera.projection = CAMERA_PERSPECTIVE;
	return camera;
	
}

