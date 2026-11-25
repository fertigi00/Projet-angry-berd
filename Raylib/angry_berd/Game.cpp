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

	// Inside your game loop:
	float deltaTime = GetFrameTime();

	LauncherInput input = inputController.capture();

	launcher.aim(input, deltaTime);

	// Get firing information
	ShotSettings shot = launcher.shotSettings();

	// When firing:
	cyclone::Vector3 velocity = shot.initialVelocity();

	// Tell the window to use vsync and work on high DPI displays
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	// Create the window and OpenGL context
	InitWindow(800, 600, "Hello Raylib");

	

	// game loop
	while (!WindowShouldClose())		// run the loop until the user presses ESCAPE or presses the Close button on the window
	{
		// drawing
		BeginDrawing();

		// Setup the back buffer for drawing (clear color and depth buffers)
		ClearBackground(BLACK);

		// draw some text using the default font
		DrawText("Hello Raylib", 200, 200, 20, WHITE);

		// end the frame and get ready for the next one  (display frame, poll input, etc...)
		EndDrawing();
	}

	// destroy the window and cleanup the OpenGL context
	CloseWindow();
}
