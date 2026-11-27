#pragma once
#include "raylib.h"
#include "InputController.h"
#include "ICameraController.h"
class cameraManager
{
public:
	cameraManager(Vector3 tgt, float dist);
	void update();
	void Begin();
	void End();

private: 
	Camera3D Camera;
	Vector3 target;
	float distance;
	float horizontal;
	float vertical;
	float zoomSpeed;
	float rotateSpeed;

};

