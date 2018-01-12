#ifndef INCLUDE_LEVEL_H
#define INCLUDE_LEVEL_H

#include <vector>
#include "Sprite.h"

class Level
{
private:
	SDL_Surface *surface = NULL;
	std::vector<Sprite*> fixedSprites;
	std::vector<Sprite*> movementSprites;
	int spritesSize = 0;

public:

	// Ctor with a surface.
	Level(SDL_Surface *s):
		surface(s)
	{}

	// Ctor of a sprite vector.
	Level(const std::vector<Sprite*> sp):
		spritesSize(sp.size()),
		fixedSprites(sp)
	{}

	// Ctor
	Level(SDL_Surface *s, const std::vector<Sprite*> sp):
		surface(s),
		spritesSize(sp.size()),
		fixedSprites(sp)
	{}

	// Copy Ctor.
	Level(const Level &sg):
		fixedSprites(sg.sprites()),
		spritesSize(sg.size())
	{}

	// Empty
	inline void empty()
	{
		fixedSprites.clear();
		spritesSize = 0;
	}

	// Get Sprites.
	inline std::vector<Sprite*> sprites() const
	{
		return fixedSprites;
	}

	// Get Size.
	inline int size() const
	{
		return spritesSize;
	}

	// Adds a sprite.
	inline void add(Sprite *s)
	{
		fixedSprites.push_back(s);
		++spritesSize;
	}

	// Adds some sprites.
	inline void add(std::vector<Sprite*> sp)
	{
		for(int i = 0; i < sp.size(); ++i)
		{
			fixedSprites.push_back(sp[i]);
			++spritesSize;
		}
	}

	// Removes a sprite.
	inline void remove(Sprite s)
	{
		for(int i = 0; i < spritesSize; ++i)
		{
			if(*fixedSprites[i] == s)
				fixedSprites.erase(fixedSprites.begin() + i);
		}

		--spritesSize;
	}

	inline bool has(Sprite s)
	{
		for(int i = 0; i < spritesSize; ++i)
		{
			if(*fixedSprites[i] == s)
				fixedSprites.erase(fixedSprites.begin() + i);
		}

		--spritesSize;
	}

	inline void update()
	{
		if(spritesSize > 0)
		{
			for(int i = 0; i < spritesSize; ++i)
				fixedSprites[i]->update();
		}
	}

	inline void draw()
	{
		for(int i = 0; i < spritesSize; i++)
			fixedSprites[i]->draw(surface);
	}
};

#endif