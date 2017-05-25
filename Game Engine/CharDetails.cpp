#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <assert.h>
#include <GL/glew.h>
#include "CharDetails.h"

/* ANIMATION FUNCTIONS */

void AnimationData::update(float deltaTime)
{
	// TO-DO update/transfer update() later
}

void AnimationData::draw(int x, int y)
{
	// TO-DO update/transfer draw() later
}

//=====================================================================//

/* CHARACTERDATA FUNCTIONS*/

CharacterData::CharacterData()
{
	startX = 1015.0f;
	startY = 135.0f;
	x = 0;
	y = 0;
	dx = 0;
	dy = 0;
	velocity = 0;
	hp = 10;
	phi = 0;
	w = 0;
	h = 0;
    isWalkingUp = false;
	isWalkingLeft = false;
	isWalkingRight = false;
	isWalkingDown = false;
	isAttacking = false;
	onStandby = false;
}

void CharacterData::update(float deltaTime)
{
	// TO-DO update/transfer update() later
}

void CharacterData::draw()
{
	// TO-DO update/transfer draw() later
}

void CharacterData::attack(GLuint spriteTex)
{
	AnimationDef animDef;
	isAttacking = true;
	curAnimation.curFrame = animDef.frames[25].image;
}

void CharacterData::speak()
{
	// TO-DO implement later
	printf("Ouch!\n");
}

void CharacterData::reset()
{
	x = startX;
	y = startY;
	hp = 10;
	phi = 3.14f;
}
