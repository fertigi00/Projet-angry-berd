
#pragma once

#include "ShotSettings.h"
#include "InputController.h"

class Launcher
{
private:
    float yaw = 0.0f;
    float pitch = 5.0f;
    float speed = 8.0f;

    Vector3 origin{ 0.0f, 0.0f, 0.0f };

    ProjectileKind projectileKind =
        ProjectileKind::Standard;

    Vector3 calculateDirection() const;

public:
    /*void aim(const LauncherInput& input, float deltaTime);*/

    ShotSettings shotSettings() const;

    void setOrigin(Vector3 newOrigin);
    void aim(const LauncherInput& input, float deltaTime);
    float getYaw() const { return yaw; }
    float getPitch() const { return pitch; }
    float getSpeed() const { return speed; }
};
