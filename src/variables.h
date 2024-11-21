#include <SDL.h>
#include <SDL_ttf.h>
#include <emscripten/emscripten.h>

extern SDL_Window *window;
extern SDL_Renderer *renderer;
extern SDL_Texture *textTexture;
extern TTF_Font *font;
extern SDL_Color textColor;

extern char *originalText;
extern char *orientationText;
extern const char *orientation;

extern bool textChange;