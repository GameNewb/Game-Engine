#ifndef CHARDETAILS_H
#define CHARDETAILS_H
#include <GL/glew.h>

/* ANIMATION META-DATA */
class FrameDef
{
public:
	int image;
	float frameTimeSecs;
};

class AnimationDef
{
public:
	std::string name;
	FrameDef frames[32];
};// animDef;

class AnimationData
{
public:	
	AnimationDef def;
	int curFrame;
	float secsUntilNextFrame;
	void update(float deltaTime);
	void draw(int x, int y);
};// animation;


//=====================================================================//
/* CHARACTER META DATA */
class CharacterDef
{
	std::string name;
	std::string walkAnimDef;
	std::string attackAnimDef;
};

class CharacterData
{
public:
	CharacterData();
	float startX;
	float startY;
	float x;
	float prevX;
	float y;
	float prevY;
	float dx;
	float dy;
	float velocity;
	float hp;
	float phi;
	int w;
	int h;
	bool isWalkingUp;
	bool isWalkingLeft;
	bool isWalkingRight;
	bool isWalkingDown;
	bool isAttacking;
	bool onStandby;
	AnimationData curAnimation;

	void update(float deltaTime);
	void draw();
	void attack(GLuint spriteTex);
	void speak();
	void reset();
};// player;

#endif