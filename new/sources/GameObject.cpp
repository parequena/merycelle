#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "TextureManager.cpp"

class GameObject
{
private:
	int x, y; // Where to place the Object.
	SDL_Texture *objTexture; // Texture of the Object.
	SDL_Rect srcRect, dstRect; // srcRect -> Image Load. dstRect -> Rect to draw on surface.
	SDL_Renderer *renderer;    // Render

public:
	GameObject(const std::string textureSheet, SDL_Renderer *rend, const int &xPos, const int &yPos)
	{
		renderer = rend;
		objTexture = TextureManager::LoadTexture(textureSheet, rend);

		x = xPos;
		y = yPos;
	}

	~GameObject()
	{

	}

	inline void update()
	{
		// Image resolution.
		srcRect.h = 40;
		srcRect.w = 40;

		srcRect.x = 0;
		srcRect.y = 0;

		// Re Scale
		dstRect.x = x;
		dstRect.y = y;

		dstRect.w = srcRect.w * 2;
		dstRect.h = srcRect.h * 2;

	}

	inline void render()
	{
		SDL_RenderCopy(renderer, objTexture, &srcRect, &dstRect);
	}
};

#endif