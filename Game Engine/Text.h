
#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <GL/glew.h>
#include <string>

class Text
{
public:
	Text(SDL_Renderer* renderer, int font_size, const std::string &message_text);//, const SDL_Color &color);

	void display(int x, int y, SDL_Renderer *renderer) const;
	static SDL_Texture *loadFont(SDL_Renderer* renderer, int font_size, const std::string &message_text);//, const SDL_Color &color);
private:
	SDL_Texture *_textTexture;
	mutable SDL_Rect _textRect;
	/*
	TTF_Font* font;
	SDL_Color textColor; // white
	SDL_Color backgroundColor; // black
	SDL_Renderer* renderer;
	SDL_Texture* solidTexture;
	SDL_Texture* blendedTexture;
	SDL_Texture* shadedTexture;
	SDL_Rect solidRect;
	SDL_Rect blendedRect;
	SDL_Rect shadedRect;
	SDL_Texture* SurfaceToTexture( SDL_Surface* surf );

	void textRender();
	bool setTTF(const std::string &fontName);
	void createTextTextures();
	void surfaceToTexture(SDL_Surface* surf, SDL_Renderer* renderer);*/
};
