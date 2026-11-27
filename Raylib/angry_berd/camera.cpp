#include "pch.h"
#include "camera.h"
#include <cmath>
cameraManager::cameraManager(Vector3 tgt, float dist)
    : target(tgt), distance(dist), horizontal(0.0f), vertical(0.3f),
    zoomSpeed(2.0f), rotateSpeed(0.01f)
{
    // Configuration de la caméra Raylib
    Camera.position = { 0, 0, dist };   // Position initiale
    Camera.target = target;           // Cible
    Camera.up = { 0, 1, 0 };            // Axe vertical
    Camera.fovy = 60.0f;              // Champ de vision
    Camera.projection = CAMERA_PERSPECTIVE;
}

void cameraManager::update(){

    if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {
        horizontal += GetMouseDelta().x * rotateSpeed; // Rotation horizontale
        vertical += GetMouseDelta().y * rotateSpeed; // Rotation verticale
    }

    // Limite la rotation verticale pour éviter les retournements
    //vertical< = Clamp(vertical, -1.4f, 1.4f);
    if (vertical > -1.4f)
    if (vertical < 1.4f)
    // Zoom avec la molette
    distance -= GetMouseWheelMove() * zoomSpeed;
    //distance = Clamp(distance, 2.0f, 50.0f); // Limite du zoom
    if (distance > 2.0f)
    if (distance < 50.0f)
    // Calcul de la position orbitale (sphère autour de la cible)
    Camera.position.x = target.x + distance * cosf(vertical) * sinf(horizontal);
    Camera.position.y = target.y + distance * sinf(vertical);
    Camera.position.z = target.z + distance * cosf(vertical) * cosf(horizontal);

    Camera.target = target; // Toujours regarder la cible
}

void cameraManager::Begin()
{
    BeginMode3D(Camera);
}

void cameraManager::End()
{
    EndMode3D();
}
