#include "pch.h"
#include "Game.h"
#include "test.h"
#include "InputController.h"
#include "Launcher.h"
#include "raylib.h"

void Game::Run()
{
	/*test t;
	//t.tzesrt();*/
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

	// Tell the window to use vsync and work on high DPI displays
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	// Create the window and OpenGL context
	InitWindow(screenWidth, screenHeight, "raylib [core] example - 3d camera free");

	Camera3D camera = { 0 };
	camera.position = Vector3{ 10.0f, 10.0f, 10.0f }; // Camera position
	camera.target = Vector3{ 0.0f, 0.0f, 0.0f };      // Camera looking at point
	camera.up = Vector3{ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
	camera.fovy = 45.0f;                                // Camera field-of-view Y
	camera.projection = CAMERA_PERSPECTIVE;             // Camera projection type

	Vector3 cubePosition = { 0.0f, 0.0f, 0.0f };

	DisableCursor();                    // Limit cursor to relative movement inside the window

	SetTargetFPS(60);
	/*const Vector3 origine = { settings.origine.x, shot.origine.y, shot.origine.z };*/
	
	// Tell the window to use vsync and work on high DPI displays
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	// Create the window and OpenGL context
	InitWindow(800, 600, "Hello Raylib");

	

	// game loop
	while (!WindowShouldClose())		// run the loop until the user presses ESCAPE or presses the Close button on the window
	{

		UpdateCamera(&camera, CAMERA_FREE);

		if (IsKeyPressed(KEY_Z)) camera.target = Vector3{ 0.0f, 0.0f, 0.0f };
		// drawing
		BeginDrawing();

		ClearBackground(RAYWHITE);

		BeginMode3D(camera);

		DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, RED);
		DrawCubeWires(cubePosition, 2.0f, 2.0f, 2.0f, MAROON);

		DrawGrid(10, 1.0f);

		EndMode3D();

		DrawRectangle(10, 10, 320, 93, Fade(SKYBLUE, 0.5f));
		DrawRectangleLines(10, 10, 320, 93, BLUE);

		DrawText("Free camera default controls:", 20, 20, 10, BLACK);
		DrawText("- Mouse Wheel to Zoom in-out", 40, 40, 10, DARKGRAY);
		DrawText("- Mouse Wheel Pressed to Pan", 40, 60, 10, DARKGRAY);
		DrawText("- Z to zoom to (0, 0, 0)", 40, 80, 10, DARKGRAY);
		

		float deltaTime = GetFrameTime();

		LauncherInput input = inputController.capture();

		launcher.aim(input, deltaTime);

		// Get firing information
		ShotSettings shot = launcher.shotSettings();

		// When firing:
		Vector3 velocity = shot.initialVelocity();

		/*DrawSphere();*/
		DrawGrid(20, 1.0);

		// end the frame and get ready for the next one  (display frame, poll input, etc...)
		EndDrawing();
	}

	// destroy the window and cleanup the OpenGL context
	CloseWindow();
}