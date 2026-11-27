
#include "pch.h"
#include "InputController.h"
#include <iostream>
LauncherInput InputController::capture() const
{
    LauncherInput input;

    // Azimuth
    if (IsKeyDown(KEY_A))
        input.yawInput -= 1.0f,
    std::cout << "left" << std::endl;
    if (IsKeyDown(KEY_D))
        input.yawInput += 1.0f,
    std::cout << "Right" << std::endl;

    // Elevation
    if (IsKeyDown(KEY_S))
        input.pitchInput -= 1.0f,
    std::cout << "DOWN" << std::endl;
    if (IsKeyDown(KEY_W))
        input.pitchInput += 1.0f,
    std::cout << "UP" << std::endl;
    // Speed
    if (IsKeyDown(KEY_Q))
        input.speedInput -= 1.0f,
    std::cout << "speed down" << std::endl;
    if (IsKeyDown(KEY_E))
        input.speedInput += 1.0f,
    std::cout << "speed up" << std::endl;
    // Projectile selection
    input.selectStandard = IsKeyPressed(KEY_ONE);
    ProjectileKind projectileKind = ProjectileKind::Standard;

    input.selectHeavy = IsKeyPressed(KEY_TWO);
     projectileKind = ProjectileKind::Heavy;

    return input;
}
