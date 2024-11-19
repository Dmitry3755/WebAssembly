#include <iostream>
#include <stdio.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include <emscripten/emscripten.h>

SDL_Window *window = nullptr;
SDL_Renderer *renderer = nullptr;
SDL_Texture *textTexture = nullptr;

const char *fontPath = "/assets/RubberNippleFactoryBlack.ttf";
const char *text = "Hello, WebAssembly!";
SDL_Color textColor = {255, 255, 255, 255};

void render()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    if (textTexture)
    {
        int textWidth, textHeight;
        SDL_QueryTexture(textTexture, nullptr, nullptr, &textWidth, &textHeight);
        SDL_Rect destRect = {100, 100, textWidth, textHeight};
        SDL_RenderCopy(renderer, textTexture, nullptr, &destRect);
    }

    SDL_RenderPresent(renderer);
}

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

    window = SDL_CreateWindow("SDL_ttf Example", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    TTF_Font *font = TTF_OpenFont(fontPath, 32);
    if (!font)
    {
        printf("Failed to load font: %s\n", TTF_GetError());
        TTF_Quit();
        SDL_Quit();
        return 1;
    }

    SDL_Surface *textSurface = TTF_RenderText_Blended(font, text, textColor);
    if (textSurface)
    {
        textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
        SDL_FreeSurface(textSurface);
    }
    else
    {
        printf("Failed to render text: %s\n", TTF_GetError());
    }

    TTF_CloseFont(font);

    emscripten_set_main_loop(render, 0, 1);

    return 0;
}