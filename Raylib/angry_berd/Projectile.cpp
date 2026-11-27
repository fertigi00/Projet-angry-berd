#include "pch.h"
#include "Projectile.h"


void fire()
{
	//// Find the first available round.
	//AmmoRound* shot;
	//for (shot = ammo; shot < ammo + ammoRounds; shot++)
	//{
	//	if (shot->type == UNUSED) break;
	//}

	//// If we didn't find a round, then exit - we can't fire.
	//if (shot >= ammo + ammoRounds) return;

	//// Set the properties of the particle
	//switch (currentShotType)
	//{
	//case PISTOL:
	//	shot->particle.setMass(2.0f); // 2.0kg
	//	shot->particle.setVelocity(0.0f, 0.0f, 35.0f); // 35m/s
	//	shot->particle.setAcceleration(0.0f, -1.0f, 0.0f);
	//	shot->particle.setDamping(0.99f);
	//	shot->type = PISTOL;
	//	break;

	//case ARTILLERY:
	//	shot->particle.setMass(200.0f); // 200kg
	//	shot->particle.setVelocity(0.0f, 30.0f, 40.0f); // 40m/s
	//	shot->particle.setAcceleration(0.0f, -20.0f, 0.0f);
	//	shot->particle.setDamping(0.99f);
	//	shot->type = ARTILLERY;
	//	break;

	//case FIREBALL:
	//	shot->particle.setMass(1.0f); // 1kg
	//	shot->particle.setVelocity(0.0f, 0.0f, 10.0f); // 10m/s
	//	shot->particle.setAcceleration(0.0f, 0.6f, 0.0f);
	//	shot->particle.setDamping(0.90f);
	//	shot->type = FIREBALL;
	//	break;

	//case LASER:
	//	shot->particle.setMass(0.1f); // 0.1kg
	//	shot->particle.setVelocity(0.0f, 0.0f, 100.0f); // 100m/s
	//	shot->particle.setAcceleration(0.0f, 0.0f, 0.0f);
	//	shot->particle.setDamping(0.99f);
	//	shot->type = LASER;
	//	break;
	//}
	//shot->particle.setPosition(0.0f, 1.5f, 0.0f);
	//shot->startTime = TimingData::get().lastFrameTimestamp;
	//shot->type = currentShotType;
	//// Clear the forces in the particle accumulator.
	//shot->particle.setAcceleration(cyclone::Vector3());
	//shot->particle.clearAccumulator();

}

