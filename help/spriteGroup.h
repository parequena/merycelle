#ifndef INCLUDE_SPRITEGROUP_H
#define INCLUDE_SPRITEGROUP_H

#include <vector>
#include "sprite.h"

class SpriteGroup {
private:
	std::vector<Sprite*> sprites;
	int spritesSize = 0;

public:

	SpriteGroup copy()
	{
		SpriteGroup newGroup;

		for(int i=0; i < spritesSize; i++)
			newGroup.add(sprites[i]);

		return newGroup;
	}

	void add(Sprite *s)
	{
		sprites.push_back(s);
		++spritesSize;
	}

	void remove(Sprite s)
	{
		for(int i = 0; i < spritesSize; i++)
		{
			if(*sprites[i] == s)
				sprites.erase(sprites.begin() + i);
		}

		--spritesSize;
	}

	bool has(Sprite s)
	{
		for(int i = 0; i < spritesSize; i++)
		{
			if(*sprites[i] == s)
				return true;
		}

		return false;
	}

	void update()
	{
		if(spritesSize > 0)
		{
			for(int i = 0; i < spritesSize; i++)
				sprites[i]->update();
		}
	}

	void draw(SDL_Surface *dest)
	{
		for(int i = 0; i < spritesSize; i++)
			sprites[i]->draw(dest);
	}
	
	void empty()
	{
		sprites.clear();
		spritesSize = 0;
	}

	int size()
	{
		return spritesSize;
	}

	inline std::vector<Sprite*> getSprites() { return sprites; };
};

#endif