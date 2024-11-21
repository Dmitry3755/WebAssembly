#include <iostream>
#include "combine.cpp"
#include "variables.h"

const char *fontPath = "/assets/RubberNippleFactoryBlack.ttf";
int textWidth, textHeight;

void textureInitialize()
{
    font = TTF_OpenFont(fontPath, 32);
    if (!font)
    {
        printf("Failed to load font: %s\n", TTF_GetError());
        TTF_Quit();
        SDL_Quit();
    }
    else
    {
        SDL_Surface *originalTextSurface = TTF_RenderText_Blended(font, originalText, textColor);
        SDL_Surface *orienationTextSurface = TTF_RenderText_Blended(font, orientationText, textColor);
        if (originalTextSurface && orienationTextSurface)
        {
            switch (*orientation)
            {
            case 'h':
            {
                textTexture = combineTextureHorizontal(renderer, originalTextSurface, orienationTextSurface);
                break;
            }
            case 'v':
            {
                textTexture = combineTextureVertical(renderer, originalTextSurface, orienationTextSurface);
                break;
            }
            default:
            {
                textTexture = combineTextureHorizontal(renderer, originalTextSurface, orienationTextSurface);
                break;
            }
            }
            SDL_FreeSurface(originalTextSurface);
            SDL_FreeSurface(orienationTextSurface);
        }
        else
        {
            printf("Failed to render text: %s\n", TTF_GetError());
        }
        TTF_CloseFont(font);
    }
}

void render()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    if (textChange)
    {
        SDL_DestroyTexture(textTexture);
        textureInitialize();
    }
    if (textTexture)
    {
        SDL_QueryTexture(textTexture, nullptr, nullptr, &textWidth, &textHeight);
        SDL_Rect destRect = {100, 100, textWidth, textHeight};
        SDL_RenderCopy(renderer, textTexture, nullptr, &destRect);
    }

    SDL_RenderPresent(renderer);
}