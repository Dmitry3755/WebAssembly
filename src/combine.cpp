#include <iostream>
#include "variables.h"

SDL_Texture *originalTextTexture = nullptr;
SDL_Texture *orientationTextTexture = nullptr;
SDL_Texture *combinedTexture = nullptr;
int combinedWidth = 0, combinedHeight = 0;

void createTexture(SDL_Renderer *renderer, SDL_Surface *originalTextSurface, SDL_Surface *orientationTextSurface)
{
    originalTextTexture = SDL_CreateTextureFromSurface(renderer, originalTextSurface);
    orientationTextTexture = SDL_CreateTextureFromSurface(renderer, orientationTextSurface);
}

void calculateCombineTextureSize(bool orienationHorizontal, int originalTextWidth, int originalTextHeight, int orientationTextWidth, int orientationTextHeight)
{
    if (orienationHorizontal)
    {
        combinedWidth = originalTextWidth + orientationTextWidth;
        combinedHeight = std::max(originalTextHeight, orientationTextHeight);
        ;
    }
    else
    {
        combinedWidth = originalTextWidth + orientationTextHeight;
        combinedHeight = orientationTextWidth;
    }
}

SDL_Texture *combineTextureHorizontal(SDL_Renderer *renderer, SDL_Surface *originalTextSurface, SDL_Surface *orientationTextSurface)
{
    int originalTextWidth, originalTextHeight, orientationTextWidth, orientationTextHeight;

    createTexture(renderer, originalTextSurface, orientationTextSurface);
    SDL_QueryTexture(originalTextTexture, nullptr, nullptr, &originalTextWidth, &originalTextHeight);
    SDL_QueryTexture(orientationTextTexture, nullptr, nullptr, &orientationTextWidth, &orientationTextHeight);
    calculateCombineTextureSize(true, originalTextWidth, originalTextHeight, orientationTextWidth, orientationTextHeight);

    combinedTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, combinedWidth, combinedHeight);
    if (!combinedTexture)
    {
        std::cerr << "Failed to create combined texture: " << SDL_GetError() << std::endl;
        return nullptr;
    }
    SDL_SetRenderTarget(renderer, combinedTexture);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_Rect originalTextRect = {0, 0, originalTextWidth, originalTextHeight};
    SDL_RenderCopy(renderer, originalTextTexture, nullptr, &originalTextRect);

    SDL_Rect orientationTextRect = {originalTextWidth, 0, orientationTextWidth, orientationTextHeight};
    SDL_RenderCopy(renderer, orientationTextTexture, nullptr, &orientationTextRect);

    SDL_SetRenderTarget(renderer, nullptr);

    return combinedTexture;
}

SDL_Texture *combineTextureVertical(SDL_Renderer *renderer, SDL_Surface *originalTextSurface, SDL_Surface *orientationTextSurface)
{
    int originalTextWidth, originalTextHeight, orientationTextWidth, orientationTextHeight;

    createTexture(renderer, originalTextSurface, orientationTextSurface);
    SDL_QueryTexture(originalTextTexture, nullptr, nullptr, &originalTextWidth, &originalTextHeight);
    SDL_QueryTexture(orientationTextTexture, nullptr, nullptr, &orientationTextWidth, &orientationTextHeight);
    calculateCombineTextureSize(false, originalTextWidth, originalTextHeight, orientationTextWidth, orientationTextHeight);

    combinedTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, combinedWidth, combinedHeight);
     if (!combinedTexture)
    {
        std::cerr << "Failed to create combined texture: " << SDL_GetError() << std::endl;
        return nullptr;
    }
    SDL_SetRenderTarget(renderer, combinedTexture);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_Rect originalTextRect = {0, 0, originalTextWidth, originalTextHeight};
    SDL_RenderCopy(renderer, originalTextTexture, nullptr, &originalTextRect);

    SDL_Rect orientationTextRect = {combinedWidth, 0, orientationTextWidth, orientationTextHeight};
    SDL_Point center = {0, 0};
    SDL_RenderCopyEx(renderer, textTexture, nullptr, &orientationTextRect, 90.0, &center, SDL_FLIP_NONE);

    SDL_SetRenderTarget(renderer, nullptr);
    return combinedTexture;
}