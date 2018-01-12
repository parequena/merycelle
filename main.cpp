// Merycelle Project
#include <iostream>
#include "sources/Game.h"

#define DF_projectName "Merycelle"
#define DF_fps 60
#define DF_windWidth  
#define DF_windHeight 360
#define DF_KeyPressed event.key.keysym.sym

const Uint32 windowFlags = SDL_WINDOW_SHOWN;

void cap_Framerate(Uint32 starting_tick)
{
	// Limits the FPS.
	if((1000 /DF_fps) > SDL_GetTicks() - starting_tick)
		SDL_Delay(1000 / DF_fps - (SDL_GetTicks() - starting_tick));
}

int main(int argc, char *argv[])
{
	Uint32 starting_tick; // For clock (tick);
	SDL_Init(SDL_INIT_EVERYTHING); // Init SDL.

	// Creating the window.
	SDL_Window *window = SDL_CreateWindow(DF_projectName, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		DF_windWidth, DF_windHeight, windowFlags);

	Sprite mainChar("sprites/R.bmp");
	Sprite level_0("sprites/level_0.bmp");

	SDL_Surface *screen = SDL_GetWindowSurface(window); // Screen variable.
	Uint32 white = SDL_MapRGB(screen->format, 255, 255, 255); // Creating white color.
	Uint32 black = SDL_MapRGB(screen->format, 0, 0, 0); // Creating black color.

	if(window == NULL)
	{
		std::cerr << "Error: Window not initialized!\n";
		std::cerr << SDL_GetError() << "\n";
	}
	else // Window has been created.
	{
		SDL_Event event;
		bool runGame = true;

		while(runGame)
		{
			starting_tick = SDL_GetTicks(); // Miliseconds since SDL_Init.

			while(SDL_PollEvent(&event))
			{
				if(event.type == SDL_QUIT) // If we close the window.
					runGame = false; // Stop game.
			}

			cap_Framerate(starting_tick); // FPS
		}

		SDL_DestroyWindow(window); // Destroy the window.
		SDL_Quit(); // Save quit.
	}

	return 0;
}

/*int main(int argc, char *argv[])
{
	Sprite menuSprite();
	map_init();
	Uint32 starting_tick; // Initialize the tick (clock).

	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window *wind = NULL;

	wind = SDL_CreateWindow(DF_projectName, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		DF_windWidth, DF_windHeight) // flags : , SDL_WINDOW_RESIZABLE);

	if(wind == NULL)
	{
		std::cerr << "Error: Window not initialized!\n";
		std::cerr << SDL_GetError() << "\n";
	}
	else // Window has been created.
	{
		SDL_Surface *screen = SDL_GetWindowSurface(wind); // Screen variable.
		Uint32 white = SDL_MapRGB(screen->format, 255, 255, 255); // Creating white color.
		Uint32 red = SDL_MapRGB(screen->format, 255, 0, 0); // Creating red color.
		Uint32 blue = SDL_MapRGB(screen->format, 0, 0, 255); // Creating blue color.

		SDL_FillRect(screen, NULL, white); // Filling the screen.
		
		Block block(red, 0, 0);
		block.setImage("R.bmp"); // Violación de segmento (`core' generado)

		SpriteGroup activeSprites;
		activeSprites.add(&block);
		activeSprites.draw(screen);

		SDL_UpdateWindowSurface(wind); // Updates the info.

		SDL_Event event;
		bool runGame = true;


		while(runGame)
		{
			starting_tick = SDL_GetTicks(); // Miliseconds since SDL_Init.
			while(SDL_PollEvent(&event))
			{
				if(event.type == SDL_QUIT) // If we close the window.
					runGame = false; // Stop game.
				else if(event.type == SDL_KEYDOWN)
				{
					if(DF_KeyPressed == SDLK_DOWN)
					{
						block.moveY(1);
						activeSprites.draw(screen);
					}
					if(DF_KeyPressed == SDLK_UP)
					{
						block.moveY(-1);
						activeSprites.draw(screen);
					}
					if(DF_KeyPressed == SDLK_LEFT)
					{
						block.moveX(-1);
						activeSprites.draw(screen);
					}
					if(DF_KeyPressed == SDLK_RIGHT)
					{
						block.moveX(1);
						activeSprites.draw(screen);
					}
				}
			}

			cap_Framerate(starting_tick); // FPS
		}

		SDL_DestroyWindow(wind); // Destroy the window.
		SDL_Quit(); // Save quit.
	}

	return 0;
}*/
