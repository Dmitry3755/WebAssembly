#include <iostream>
#include <stdio.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include <emscripten/emscripten.h>

SDL_Window *window = nullptr;
SDL_Renderer *renderer = nullptr;

void main_loop()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

	SDL_Rect rect;
	rect.x = 100;
	rect.y = 100;
	rect.w = 200;
	rect.h = 200;

	SDL_RenderFillRect(renderer, &rect);

	SDL_RenderPresent(renderer);
}

int main()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		printf("SDL_Init failed: %s\n", SDL_GetError());
		return 1;
	}

	window = SDL_CreateWindow("Text Display", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL);
	if (!window)
	{
		printf("SDL_CreateWindow failed: %s\n", SDL_GetError());
		return 1;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (!renderer)
	{
		printf("SDL_CreateRenderer failed: %s\n", SDL_GetError());
		return 1;
	}

	emscripten_set_main_loop(main_loop, 0, 1);

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}