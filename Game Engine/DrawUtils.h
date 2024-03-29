#ifndef DRAWUTILS_H
#define DRAWUTILS_H

/*
#ifdef __cplusplus
extern "C" {
#endif*/

	GLuint glTexImageTGAFile(const char* filename, int* outWidth, int* outHeight);
	void glDrawSprite(GLuint tex, int x, int y, int w, int h);
	void glDrawTiles(GLuint tile, int TILE_X, int TILE_Y, int ENDPOINT_X, int ENDPOINT_Y, int w, int h);

	/*
#ifdef __cplusplus
}
#endif*/

#endif
