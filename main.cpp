// Merycelle Project
#include <iostream>
#include "sprite.h"
#include <vector>

#define DF_projectName "Merycelle"
#define DF_fps 60
#define DF_windWidth 400
#define DF_windHeight 200

void cap_Framerate(Uint32 starting_tick)
{
	// Limits the FPS.
	if((1000 /DF_fps) > SDL_GetTicks() - starting_tick)
		SDL_Delay(1000 / DF_fps - (SDL_GetTicks() - starting_tick));
}

int main(int argc, char *argv[])
{
	Uint32 starting_tick;

	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window *wind = NULL;

	wind = SDL_CreateWindow(DF_projectName, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		DF_windWidth, DF_windHeight, SDL_WINDOW_RESIZABLE);

	if(wind == NULL)
	{
		std::cerr << "Error: Window not initialized!\n";
		std::cerr << SDL_GetError() << "\n";
	}
	else // Window has been created.
	{
		SDL_Surface *screen = SDL_GetWindowSurface(wind); // Screen variable.
		Uint32 white = SDL_MapRGB(screen->format, 255, 255, 255); // Creating white color.
		Uint32 red = SDL_MapRGB(screen->format, 255, 0, 0); // Creating white color.

		SDL_FillRect(screen, NULL, white); // Filling the screen.

		Sprite redBox(red, DF_windWidth/2, DF_windHeight/2);
		redBox.draw(screen);

		SDL_UpdateWindowSurface(wind); // Updates the info.

		SDL_Event event;
		bool runGame = true;


		while(runGame)
		{
			starting_tick = SDL_GetTicks(); // Miliseconds since SDL_Init.
			while(SDL_PollEvent(&event))
			{
				if(event.type == SDL_QUIT) // If we close the window.
				{
					runGame = false; // Stop game.
					break;
				}
			}

			cap_Framerate(starting_tick); // FPS
		}

		SDL_DestroyWindow(wind); // Destroy the window.
		SDL_Quit(); // Save quit.
	}

	return 0;
}
