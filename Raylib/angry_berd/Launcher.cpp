
#include "pch.h"
#include "Launcher.h"

#include "raymath.h"
#include <algorithm>
#include <cmath>

namespace
{
    constexpr float DEG_TO_RAD =
        3.14159265358979323846f / 180.0f; // find ion the net

    constexpr float YAW_RATE = 60.0f;
    constexpr float PITCH_RATE = 60.0f;
    constexpr float SPEED_RATE = 5.0f;
}

void Launcher::aim(const LauncherInput& input, float deltaTime)
{
    deltaTime = std::max(deltaTime, 0.0f);

    // Update yaw
    yaw += input.yawInput * YAW_RATE * deltaTime;

    // Update pitch
    pitch += input.pitchInput * PITCH_RATE * deltaTime;

    // Update speed
    speed += input.speedInput * SPEED_RATE * deltaTime;

    // Clamp values
    yaw = std::clamp(yaw, -30.0f, 30.0f);
    pitch = std::clamp(pitch, 5.0f, 55.0f);
    speed = std::clamp(speed, 8.0f, 22.0f);

    // Projectile selection
    if (input.selectStandard)
        projectileKind = ProjectileKind::Standard;

    if (input.selectHeavy)
        projectileKind = ProjectileKind::Heavy;
}

Vector3 Launcher::calculateDirection() const
{
    const float yawRadians = yaw * DEG_TO_RAD;
    const float pitchRadians = pitch * DEG_TO_RAD;

    Vector3 direction;

    direction.x = std::cos(yawRadians) *
        std::cos(pitchRadians);

    direction.y = std::sin(pitchRadians);

    direction.z = std::sin(yawRadians) *
        std::cos(pitchRadians);

    // Ensure normalized direction
    return Vector3Normalize(direction);
}

ShotSettings Launcher::shotSettings() const
{
    ShotSettings settings;

    settings.origin = origin;
    settings.direction = calculateDirection();
    settings.speed = speed;
    settings.projectileKind = projectileKind;

    return settings;
}

void Launcher::setOrigin(Vector3 newOrigin)
{
    origin = newOrigin;
}
