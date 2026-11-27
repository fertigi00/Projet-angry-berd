#pragma once

#include "raylib.h"

enum class ProjectileKind
{
    Standard,
    Heavy
};

struct ShotSettings
{
    Vector3 origin;
    Vector3 direction;

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
