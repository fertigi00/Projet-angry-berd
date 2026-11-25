#include "pch.h"
#include "FreeCamera.h"
void FreeCamera::update(InputController::InputSnapshot& inputs, float duration) {
	if (input.key_d)
		m_position.x += 0.5;
}
Camera3D FreeCamera::getCamera() {
	Camera3D Camera = { 0 };
	camera.position = m_position;
	camera.target = { 0.0f, 0.0f, 0.0f };
	camera.up = { 0.0f, 0.0f, 0.0f };
	camera.fovy = 45.0f;
	camera.projecvtion = CAMERA_PERSPECTIVE;
	return camera;
}