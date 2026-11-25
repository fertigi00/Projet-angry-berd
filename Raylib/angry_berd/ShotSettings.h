#pragma once

#include "raylib.h"

enum class ProjectileKind
{
    Standard,
    Heavy
};

struct ShotSettings
{
    Vector3 origin{ 0.0f, 0.0f, 0.0f };
    Vector3 direction{ 1.0f, 0.0f, 0.0f };

    float speed = 8.0f;

    ProjectileKind projectileKind = ProjectileKind::Standard;

    Vector3 initialVelocity()
    {
        return Vector3{
            direction.x * speed,
            direction.y * speed,
            direction.z * speed
        };
    }
};
