#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include "SDL.h"
#include "SDL_image.h"


class TextureManager
{
public:
	inline static SDL_Texture *LoadTexture(const std::string fileName, SDL_Renderer *r)
	{
		SDL_Surface *tmpSurface = IMG_Load(fileName.c_str());
		SDL_Texture *tex = SDL_CreateTextureFromSurface(r, tmpSurface);
		SDL_FreeSurface(tmpSurface);

		return tex;
	}

};

#endif