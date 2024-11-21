#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_render.h>
#include <emscripten/emscripten.h>
#include "variables.h"
#include "render.cpp"

SDL_Window *window = nullptr;
SDL_Renderer *renderer = nullptr;
SDL_Texture *textTexture = nullptr;
TTF_Font *font = nullptr;
SDL_Color textColor = {255, 255, 255, 255};

bool textChange = false;
char *originalText = nullptr;
char *orientationText = nullptr;
const char *orientation = nullptr;

int main()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("SDL_Init failed: %s\n", SDL_GetError());
        return 1;
    }

    if (TTF_Init() != 0)
    {
        printf("TTF_Init failed: %s\n", TTF_GetError());
        SDL_Quit();
        return 1;
    }

    window = SDL_CreateWindow("WebAssembly", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    textureInitialize();
    emscripten_set_main_loop(render, 0, 1);

    return 0;
}