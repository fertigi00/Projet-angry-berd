#pragma once
#include "../Cyclone/include/body.h"
#include "../Cyclone/include/collide_fine.h"
#include "../Cyclone/src/body.cpp"
#include "../Cyclone/src/collide_fine.cpp"
#include "../Cyclone/include/contacts.h"
#include "../Cyclone/src/contacts.cpp"
#include "../Cyclone/include/core.h"
#include "../Cyclone/include/particle.h"
class Projectile
{
public:
    void fire();
    //particle.setMass(1.0f); // 1kg
    //particle.setVelocity(0.0f, 0.0f, 10.0f); // 10m/s
    //particle.setAcceleration(0.0f, 0.6f, 0.0f);
    //particle.setDamping(0.90f);
};

