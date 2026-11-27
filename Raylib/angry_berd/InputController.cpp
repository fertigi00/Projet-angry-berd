
#include "pch.h"
#include "InputController.h"
#include <iostream>
LauncherInput InputController::capture() const
{
    LauncherInput input;

    // Azimuth
    if (IsKeyDown(KEY_A))
        input.yawInput -= 1.0f;

        if (IsKeyDown(KEY_D))
            input.yawInput += 1.0f;

    // Elevation
        if (IsKeyDown(KEY_S))
            input.pitchInput -= 1.0f;
        if (IsKeyDown(KEY_W))
            input.pitchInput += 1.0f;
    // Speed
        if (IsKeyDown(KEY_Q))
            input.speedInput -= 1.0f;
        if (IsKeyDown(KEY_E))
            input.speedInput += 1.0f;

    // Projectile selection
    input.selectStandard = IsKeyPressed(KEY_ONE);
    ProjectileKind projectileKind = ProjectileKind::Standard;

    input.selectHeavy = IsKeyPressed(KEY_TWO);
     projectileKind = ProjectileKind::Heavy;

    return input;
}
