#ifndef INCLUDE_GAME_H
#define INCLUDE_GAME_H

#include "Level.h"

class Game
{
private:
	int currentLevel; // Current level that we are playing.
	int levelSize; // Level size.
//	Sprite character; // Main character sprite.
	std::vector<Level> levels; // All levels.

public:

	// Ctor.
	Game()
	{
		currentLevel = 0;
	}

	// Ctor with a level.
	Game(Level l):
		currentLevel(0),
		levelSize(1)
	{
		levels.push_back(l);
	}

	// Get size.
	inline int size()
	{
		return levelSize;
	}

	// Gets the current level
	inline Level level()
	{
		return levels[currentLevel];
	}

	// Adds a level.
	inline void add(Level l)
	{
		++levelSize;
		levels.push_back(l);
	}

	// Adds some levels.
	inline void add(std::vector<Level> ls)
	{
		for(int i = 0; i < ls.size(); ++i)
		{
			levels.push_back(ls[i]);
			++levelSize;
		}
	}

	/*inline void character(Sprite s)
	{
		character = s;
	}*/
};

#endif