#pragma once
#include "pch.h"
#include "..\Cyclone\include\cyclone.h"

class SceneObjects
{
public:
	void SceneObject();
	void create();
	void getPosition();
	void getID();
	void destroy();
	void forEach();
	void clear();
	int id;
	bool isAlive;
	int amountToPool;

	struct Entity
	{
        cyclone::Particle particle;
        unsigned startTime;

        /** Draws the round. */
        void render()
        {
            cyclone::Vector3 position;
            particle.getPosition(&position);

        }
	};
};

