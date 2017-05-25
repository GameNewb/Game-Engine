#ifndef TILE_H
#define TILE_H
#include <SDL.h>
#include <GL/glew.h>
#include <string>

/* TILE META-DATA */

class Tile
{
public:
	Tile();
	int tileMap[64][64];
	int x;
	int y;
	int w;
	int h;
	int depth;
	int value;
	int tileType; // 0 = grass/tree, 1 = water tile or tiles that projectiles can pass through
	int TILE_WIDTH;
	int TILE_HEIGHT;
	int STUMP_WIDTH;
	int STUMP_HEIGHT;
	int TREE_WIDTH;
	int TREE_HEIGHT;
	int BIG_TREE_WIDTH;
	int BIG_TREE_HEIGHT;
	GLuint image;
	bool collidable;

	void setTile(int i, int j);
	int getTileMap(int i, int j);
};


#endif