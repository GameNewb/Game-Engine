#ifndef OBJECT_H
#define OBJECT_H
#include <GL/glew.h>
#include <SDL.h>

class Object
{
public:
	Object();
	float x;
	float y;
	float dx;
	float dy;
	float phi;
	int w;
	int h;
	int damage;
	GLuint sprite;
	bool isActive;
	bool isCollideable;
};

#endif