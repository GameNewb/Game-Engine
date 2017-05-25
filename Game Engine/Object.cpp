#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <assert.h>
#include <GL/glew.h>
#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include "Object.h"


Object::Object()
{
	x = 0;
	y = 0;
	w = 0;
	h = 0;
	dx = 0;
	dy = 0;
	damage = 0;
	isCollideable = true;
};
