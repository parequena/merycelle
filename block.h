#ifndef INCLUDE_BLOCK_H
#define INCLUDE_BLOCK_H

#include "sprite.h"
#include "SDL_image.h"

class Block : public Sprite {
public:
	Block(const Uint32 color, const int x, const int y, const int w = 48, const int h = 64):
	Sprite(color, x, y, w, h)
	{
		updatePropierties();				
	}

	void updatePropierties()
	{
		origin_X = 0;
		origin_Y = 0;

		setPosition(rect.x, rect.y);
	}

	void setPosition(int x, int y)
	{
		rect.x = x - origin_X;	
		rect.y = y - origin_Y;
	}

	void setImage(const std::string str = NULL)
	{
		if(!str.empty())
		{
			SDL_Surface *loadedImage = NULL;

			loadedImage = IMG_Load(str.c_str());

			if(!str.empty())
			{
				image = loadedImage;

				int old_X = rect.x, old_Y = rect.y;

				rect = image->clip_rect;

				rect.x = old_X;
				rect.y = old_Y;

				updatePropierties();
			}
		}
	}

	void moveX(const int &units)
	{
		if(rect.x + units >= 0 && rect.x + rect.w + units <= 800)
		{
			setPosition(rect.x + units ,rect.y);
		}
	}

	void moveY(const int &units)
	{
		if(rect.y + units >= 0 && rect.y + rect.h + units <= 400)
		{
			setPosition(rect.x,rect.y + units);
		}
	}
};

#endif