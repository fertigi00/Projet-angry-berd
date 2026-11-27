#include "pch.h"
#include "Game.h"
#include "test.h"
#include "InputController.h"
#include "Launcher.h"
#include "raylib.h"
#include "camera.h"

void Game::Run()
{
	InputController inputController;
	Launcher launcher;

	const int screenWidth = 800;
	const int screenHeight = 450;
	// Inside your game loop:
	float deltaTime = GetFrameTime();

	LauncherInput input = inputController.capture();

	launcher.aim(input, deltaTime);

	// Get firing information
	ShotSettings shot = launcher.shotSettings();


	Vector3 cubePosition = { 0.0f, 0.0f, 0.0f };

	
	// Tell the window to use vsync and work on high DPI displays
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	// Create the window and OpenGL context
	InitWindow(screenWidth, screenHeight, "raylib [core] example - 3d camera free");

	cameraManager cam({ 0,0,0 }, 10.0f);

	DisableCursor();                    // Limit cursor to relative movement inside the window

	SetTargetFPS(60);

	// game loop
	while (!WindowShouldClose())		// run the loop until the user presses ESCAPE or presses the Close button on the window
	{

		float deltaTime = GetFrameTime();

		LauncherInput input = inputController.capture();

		launcher.aim(input, deltaTime);

		// Get firing information
		ShotSettings shot = launcher.shotSettings();
		const bool heavy = (shot.projectileKind == ProjectileKind::Heavy);
		Vector3 velocity = shot.initialVelocity();
		//see move
		const Vector3 origine = { shot.origin.x, shot.origin.y, shot.origin.z };
		const float length = shot.speed * 0.4f;
		const Vector3 tip = {
		origine.x + shot.direction.x * length,
		origine.y + shot.direction.y * length,
		origine.z + shot.direction.z * length
		};

		// drawing
		cam.update();

		BeginDrawing();

		ClearBackground(RAYWHITE);
		//to SEE THE 3D
		cam.Begin();

		DrawGrid(10, 1.0f);

		DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, RED);
		DrawCubeWires(cubePosition, 2.0f, 2.0f, 2.0f, MAROON);
		//luncher
		DrawGrid(20, 1.0);
		DrawSphere(origine, heavy ? 0.36f : 0.28f, heavy ? DARKPURPLE : BLUE);
		DrawLine3D(origine, tip, MAGENTA);
		DrawSphere(tip, 0.1f, MAGENTA);

		cam.End();

		DrawRectangle(10, 10, 320, 93, Fade(SKYBLUE, 0.5f));
		DrawRectangleLines(10, 10, 320, 93, BLUE);

		
		
		DrawText(TextFormat("Azimut    : %.1f deg", launcher.getYaw()), 10, 10, 20, DARKGRAY);
		DrawText(TextFormat("Elevation : %.1f deg", launcher.getPitch()), 10, 34, 20, DARKGRAY);
		DrawText(TextFormat("Vitesse   : %.1f m/s", launcher.getSpeed()), 10, 58, 20, DARKGRAY);
		DrawText(TextFormat("Projectile: %s", heavy ? "Heavy" : "Standard"), 10, 82, 20, DARKGRAY);
		

		


		// end the frame and get ready for the next one  (display frame, poll input, etc...)
		EndDrawing();
	}

	// destroy the window and cleanup the OpenGL context
	CloseWindow();
}