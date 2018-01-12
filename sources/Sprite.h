#ifndef INCLUDE_SPRITE_H
#define INCLUDE_SPRITE_H

#include "SDL.h"
#include "SDL_image.h"

class Sprite
{
private:
	SDL_Surface *image;
	SDL_Rect rect;

public:
	// Ctor for an image.
	Sprite(const std::string &filename = NULL)
	{
		if(!filename.empty())
		{
			image = IMG_Load(filename.c_str());

			if(image != NULL)
				rect = image->clip_rect;
		}
	}

	// Ctor for a color.
	Sprite(Uint32 color, int x, int y, int w, int h)
	{
		image = SDL_CreateRGBSurface(0, w, h, 32, 0, 0, 0, 0); // flags, width, height, depth, rmask, gmask, bmask, amask
		SDL_FillRect(image, NULL, color); // Null for all size.

		rect = image->clip_rect;
		
		rect.x = x;
		rect.y = y;
	}

	// Update Sprite.
	inline void update()
	{
		// Can be overriten!
	}

	// Draws on a surface.
	inline void draw(SDL_Surface *destination)
	{
		SDL_BlitSurface(image, NULL, destination, &rect);
	}

	// Gets image.
	inline SDL_Surface *getImage() const
	{
		return image;
	}


 	// Sets image.
	inline void setImage(SDL_Surface *im)
	{
		if(im != NULL)
			image = im;
	}


	// Operator ==.
	inline bool operator==(const Sprite &s) const
	{
		return image == s.getImage();
	}

	// Operator !=.
	inline bool operator!=(const Sprite &s) const
	{
		return image != s.getImage();
	}
};

#endif