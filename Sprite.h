#ifndef INCLUDE_SPRITE_H
#define INCLUDE_SPRITE_H

#include "SDL.h"
#include "SDL_image.h"

#define DF_Path "."

class Sprite
{
private:
	SDL_Surface *image;
	SDL_Rect *rect;

public:

	Sprites(const std::string &filename = NULL, const int &x, const int &y, const int &w, const int &h)
	{

	}

	Sprites(const Uint32 &color, const int &x, const int &y, const int &w, const int &h)
	{

	}

	inline SDL_Surface *image() const { return image; };
	inline void image(SDL_Surface *s) const { image = s; };
}

#endif