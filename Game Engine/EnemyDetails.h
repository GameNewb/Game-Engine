#ifndef ENEMYDETAILS_H
#define ENEMYDETAILS_H
#include <SDL.h>
#include <GL/glew.h>
#include <vector>
#include <math.h>
#include <assert.h>
#include <time.h>

class EnemyFrameDef
{
public:
	int image;
	float frameTimeSecs;
};

class EnemyAnimationDef
{
public:
	EnemyFrameDef frames[36];
};

class EnemyAnimationData
{
public:	
	EnemyAnimationDef def;
	int curFrame;
	float secsUntilNextFrame;
};

// Enemy class
class EnemyData
{
public:
	EnemyData();
	float health;
	float x;
	float y;
	float dx;
	float dy;
	float w;
	float h;
	float phi;
	float speed;
	float distance[2];
	long decisionTimer;
	float decisionMade;
	float deathTimer;

	// Projectile properties
	GLuint projectile;
	long projectileCounter;
	long projectileGap;
	long secsUntilNextProjectile;
	bool projectileIsSet;

	bool onStandby;
	bool movingLeft;
	bool movingRight;
	bool movingUp;
	bool movingDown;
	bool needDecision;
	EnemyAnimationData curAnimation;
	void speak();
	void reset(int i);
	float makeDecision();
	void setDecision(float decisionNumber);
	float getDecision();
	void executeDecision(int deltaTime, float decisionNumber);
	void walkAround(int deltaTime, float randomNumber);
	void beIdle(int deltaTime);
	void chasePlayer(int deltaTime);
	void setProjectile(long deltaTime, long enemySecsUntilNextProjectile);
	void moveProjectile();
	float randomGenerator();
	float randomGenerator2(float MAX, float MIN);
};


#endif