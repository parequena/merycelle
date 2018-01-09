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
			if()
		}

		--spritesSize;
	}
	
	inline vector<Sprite*> getSprites() { return sprites; };
}

#endif