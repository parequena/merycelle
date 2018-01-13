#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "GameObject.cpp"

#define DF_MainCharSprite "sprites/main.png"
#define DF_1 "sprites/R.bmp"

// Flags for Window creation.
const Uint32 flags = 0;

class Game
{
private:
	int cnt;
	bool isRunning = false;
	SDL_Window *window;
	SDL_Renderer *renderer;
	GameObject *mainPlayer, *otherObject;

public:
	// Ctor
	Game(const std::string &title, const int &x, const int &y, const int &w, const int &h)
	{
		if(SDL_Init(SDL_INIT_EVERYTHING) == 0) // All good.
		{
			window = SDL_CreateWindow(title.c_str(), x, y, w, h, flags);

			if(!window)
				std::cerr << "Error: Window creation failed.\n";

			renderer = SDL_CreateRenderer(window, -1, 0);
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0); // Render to white.

			if(!renderer)
				std::cerr << "Error: Renderer creation failed.\n";

			isRunning = true;
		}
		else
			std::cerr << "Error: Init failed.\n";

		mainPlayer = new GameObject(DF_MainCharSprite, renderer, 0, 0);
		otherObject = new GameObject(DF_1, renderer, 100, 100);
	}

	// Dtor
	~Game()
	{

	}

	inline void handleEvents()
	{
		SDL_Event event;
		SDL_PollEvent(&event);

		switch (event.type)
		{
			case SDL_QUIT:
				isRunning = false;
				break;
		}
	}

	inline void update()
	{
		mainPlayer->update();
		otherObject->update();
	}

	inline void render()
	{
		SDL_RenderClear(renderer);
		// Textures to render.
		// Background -> Top.
		mainPlayer->render();
		otherObject->render();
		SDL_RenderPresent(renderer);
	}

	inline void clear()
	{
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
	}

	inline bool running()
	{
		return isRunning;
	}
};

#endif