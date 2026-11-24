#pragma once

#include "../Cyclone/include/core.h"

enum class ProjectileKind
{
    Standard,
    Heavy
};

struct ShotSettings
{
    cyclone::Vector3 origin{ 0.0f, 0.0f, 0.0f };
    cyclone::Vector3 direction{ 1.0f, 0.0f, 0.0f };

    float speed = 8.0f;

    ProjectileKind projectileKind = ProjectileKind::Standard;

    cyclone::Vector3 initialVelocity() const
    {
        return cyclone::Vector3{
            direction.x * speed,
            direction.y * speed,
            direction.z * speed
        };
    }
};
