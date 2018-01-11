#ifndef INCLUDE_SPRITE_H
#define INCLUDE_SPRITE_H

#include "SDL.h"

class Sprite {
protected:
	SDL_Surface *image;
	SDL_Rect rect;

	int origin_X, origin_Y;

public:

	/*Sprite(const std::string filename = NULL, const int x = 0, const int y = 0, const int w, const int h)
	{

	}*/ 

	Sprite(const Uint32 color, const int x, const int y, const int w, const int h)
	{
		image = SDL_CreateRGBSurface(0, w, h, 32, 0, 0, 0, 0); // flags, width, height, depth, rmask, gmask, bmask, amask
		SDL_FillRect(image, NULL, color);

		rect = image->clip_rect;

		origin_X = rect.w / 2; // Origin X (left-top corner)
		origin_Y = rect.h / 2; // Origin Y (left-top corner)

 		// Relative X and Y.
		rect.x = x;
		rect.y = y;
	}

	inline void update()
	{
		// Can be overriten!
	}

	inline void draw(SDL_Surface *dest) { SDL_BlitSurface(image, NULL, dest, &rect); };

	inline SDL_Surface *getImage() const { return image; };

	inline void setImage(SDL_Surface *im) { image = im; };

	inline int getOriginX() { return origin_X; };

	inline void setOriginX(int o) { origin_X = o; };

	inline int getOriginY() { return origin_Y; }

	inline void setOriginY(int o) { origin_Y = o; };

	bool operator==(const Sprite &s) const
	{
		return image == s.getImage();
	}

};

#endif