#include "pch.h"
#include "Projectile.h"


void Particle::integrate(real duration)
{
    // We don't integrate things with zero mass.
    if (inverseMass <= 0.0f) return;

    assert(duration > 0.0);
    position.addScaledVector(velocity, duration);
    Vector3 resultingAcc = acceleration;
    resultingAcc.addScaledVector(forceAccum, inverseMass);

    velocity.addScaledVector(resultingAcc, duration); //graviter so no gravoti

    /*Dampé*/ velocity *= real_pow(damping, duration);

    // Clear the forces.
    clearAccumulator();
}