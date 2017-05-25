#include <stdio.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <GL/glew.h>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "Text.h"

Text::Text(SDL_Renderer* renderer, int font_size, const std::string &message_text)//, const SDL_Color &color)
{
	_textTexture = loadFont(renderer, font_size, message_text);//, color);
	SDL_QueryTexture(_textTexture, nullptr, nullptr, &_textRect.w, &_textRect.h);
}

void Text::display(int x, int y, SDL_Renderer *renderer) const
{
	_textRect.x = x;
	_textRect.y = y;
	SDL_RenderCopy(renderer, _textTexture, nullptr, &_textRect);
}

SDL_Texture *Text::loadFont(SDL_Renderer* renderer, int font_size, const std::string &message_text)//, const SDL_Color &color)
{
	TTF_Font *font = TTF_OpenFont("sketchy.ttf", font_size);
	if(!font){
		std::cerr << "Failed to load font\n";
	}
	SDL_Color color = { 255, 0, 0, 255 };
	auto text_surface = TTF_RenderText_Solid(font, message_text.c_str(), color);
	if(!text_surface)
	{
		std::cerr << "Failed to create text surface\n";
	}

	auto text_texture = SDL_CreateTextureFromSurface(renderer, text_surface);
	if(!text_texture)
	{
		std::cerr << "Failed to create text texture\n";
	}

	SDL_FreeSurface(text_surface);
	return text_texture;
}


/*
Text::Text()
{
	//textColor = { 255, 255, 255, 255 }; // white
	//SDL_Color backgroundColor = { 0, 0, 0, 255 }; // black
}

void Text::textRender()
{
	// Render our text objects ( like normal )
	SDL_RenderCopy( renderer, solidTexture, nullptr, &solidRect ); 
	SDL_RenderCopy( renderer, blendedTexture, nullptr, &blendedRect ); 
	SDL_RenderCopy( renderer, shadedTexture, nullptr, &shadedRect ); 

	// Render the changes above
	SDL_RenderPresent( renderer);
}

bool Text::setTTF( const std::string &fontName)
{
	// SDL2_TTF needs to be initialized just like SDL2
	if ( TTF_Init() == -1 )
	{
		fprintf(stderr, "Could not initialize Fonts. ErrorCode = %s\n", SDL_GetError());
		return false;
	}

	// Load our fonts, with a huge size
	font = TTF_OpenFont( fontName.c_str(), 90 );
	
	// Error check
	if ( font == nullptr )
	{
		fprintf(stderr, "Could not load font. ErrorCode = %s\n", SDL_GetError());
		return false;
	}

	return true;
}

/*
void Text::createTextTextures()
{
	SDL_Surface* solid = TTF_RenderText_Solid( font, "solid", textColor );
	solidTexture = SurfaceToTexture( solid );

	SDL_QueryTexture( solidTexture, NULL, NULL, &solidRect.w, &solidRect.h );
	solidRect.x = 0;
	solidRect.y = 0;

	SDL_Surface* blended = TTF_RenderText_Blended( font, "blended", textColor );
	blendedTexture = SurfaceToTexture( blended );

	SDL_QueryTexture( blendedTexture, NULL, NULL, &blendedRect.w, &blendedRect.h );
	blendedRect.x = 0;
	blendedRect.y = solidRect.y + solidRect.h +  20;

	SDL_Surface* shaded = TTF_RenderText_Shaded( font, "shaded", textColor, backgroundColor );
	shadedTexture = SurfaceToTexture( shaded );

	SDL_QueryTexture( shadedTexture , NULL, NULL, &shadedRect.w, &shadedRect.h );
	shadedRect.x = 0;
	shadedRect.y = blendedRect.y + blendedRect.h + 20;
}

// Convert an SDL_Surface to SDL_Texture. We've done this before, so I'll keep it short
SDL_Texture* surfaceToTexture( SDL_Surface* surf , SDL_Renderer* renderer)
{
	SDL_Texture* text;

	text = SDL_CreateTextureFromSurface( renderer, surf );

	SDL_FreeSurface( surf );

	return text;
}
/*
void SetupRenderer()
{
	// Set size of renderer to the same as window
	SDL_RenderSetLogicalSize( renderer, windowRect.w, windowRect.h );

	// Set color of renderer to red
	SDL_SetRenderDrawColor( renderer, 255, 0, 0, 255 );
}*/

