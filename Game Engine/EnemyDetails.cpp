#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <assert.h>
#include <SDL.h>
#include <GL/glew.h>
#include <vector>
#include <math.h>
#include <assert.h>
#include <time.h>
#include "EnemyDetails.h"

EnemyData::EnemyData()
{
	x = 0;
	y = 0;
	w = 0;
	h = 0;
	phi = 0;
	speed = 0.13f;
	decisionTimer = 40.f;
	projectileCounter = 180;
	deathTimer = 300;
	distance[0] = 0;
	distance[1] = 0;
	onStandby = true;
	movingLeft = false;
	movingRight = false;
	movingUp = false;
	movingDown = false;
	needDecision = true;
	
	srand(static_cast <unsigned> (time(0)));
}

void EnemyData::speak()
{
	// TO-DO implement later
	printf("RAWR\n");
}

float EnemyData::makeDecision()
{
	float decision = randomGenerator();

	return decision;
}

void EnemyData::executeDecision(int deltaTime, float decisionNumber)
{
	// Reset
	movingLeft = false;
	movingRight = false;
	movingUp = false;
	movingDown = false;
	onStandby = false;

	if(decisionNumber <= .25f) // Walk
	{
		walkAround(deltaTime, decisionNumber);
	}
	else // Just be idle most of the time
	{
		beIdle(deltaTime);
	}
}

void EnemyData::setDecision(float decisionNumber)
{
	// Set each decision of each enemy
	decisionMade = decisionNumber;
}

float EnemyData::getDecision()
{
	return decisionMade;
}

void EnemyData::walkAround(int deltaTime, float decisionNumber)
{
	if(decisionNumber >= .0f && decisionNumber <= .05f) // Move left  && timer <= 5
	{
		movingLeft = true;
		x -= speed * deltaTime;
	}
	else if(decisionNumber > .05f && decisionNumber <= .10f) // Move right
	{
		movingRight = true;
		x += speed * deltaTime;
	}
	else if(decisionNumber > .10f && decisionNumber <= .15f) // Move up
	{
		movingUp = true;
		y -= speed * deltaTime;	
	}
	else if(decisionNumber > .20f && decisionNumber <= .25f) // Move down
	{
		movingDown = true;
		y += speed * deltaTime;
	}
	
}

void EnemyData::beIdle(int deltaTime)
{
	onStandby = true;
	if(decisionTimer > 0)
	{
		decisionTimer--;
	}
}

void EnemyData::chasePlayer(int deltaTime)
{
}

void EnemyData::reset(int i)
{
	if(i <= 20)
	{
		x = randomGenerator2(1600.f, 350.f);
		y = randomGenerator2(1700.f, 300.f);
		w = 42;
		h = 40;
		health = 5;
	}
	else
	{	
		x = randomGenerator2(1400.f, 300.f);
		y = randomGenerator2(2950.f, 2800.f);
		w = 42;
		h = 40;
		health = 10;
		speed = 0.18f;
	}
}

// Will move from main later
void EnemyData::setProjectile(long deltaTime, long enemySecsUntilNextProjectile)
{
	int i = 0;
	projectileGap = projectileCounter - secsUntilNextProjectile; //Delta time for projectile
	
	for(int j = 0; j < 10; j++)
	{
		// Set projectile properties
		if(distance[0] <= 150 && distance[1] <= 150 && projectileGap <= 0)
		{
			// 10 projectiles on the screen
			for(int i = 0; i < 10; i++)
			{
				/*
				if(enemyProj[i].isActive == false)
				{
					enemyProj[i].isActive = true;
					enemyProj[i].x = x+(h/2);
					enemyProj[i].y = y+(w/2);
					enemyProj[i].dx = sin(phi) * (deltaTime * 0.15f);
					enemyProj[i].dy = cos(phi) * (-deltaTime * 0.15f);
					
					enemyProjectileCounter = 160;
					break;
				}*/
			}

			enemySecsUntilNextProjectile = 0;
		}
	}
}

void EnemyData::moveProjectile()
{
}

float EnemyData::randomGenerator()
{
	float MAX = 1.0f;
	float MIN = .01f;

	float random = (float) rand() / (float) (RAND_MAX);
	//printf("RAND %f\n:", random);
	return random;
}

float EnemyData::randomGenerator2(float MAX, float MIN)
{
	//float random = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/ (MAX + MIN)));
	float random = MIN + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/ (MAX - MIN)));

	return random;
}