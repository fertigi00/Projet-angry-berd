#pragma once
#include "pch.h"
#include "..\Cyclone\include\cyclone.h"

class ObjectPool
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
	virtual void key(unsigned char key);
	struct Entity
	{
        cyclone::Particle particle;
        unsigned startTime;

        /** Draws the round. */
        void render()
        {
            cyclone::Vector3 position;
            particle.getPosition(&position);


			/*glColor3f(0, 0, 0);
			glPushMatrix();
			glTranslatef(position.x, position.y, position.z);
			glutSolidSphere(0.3f, 5, 4);
			glPopMatrix();*/
			
        }
	};
};

