  
#ifndef UTIL_HPP_
#define UTIL_HPP_

#include <SDL2/SDL.h>

#define ASSERT(x) if(!(x)){printf("ERROR: \nFILE %s\nFUNCTION %s\n LINE %d\n", __FILE__, __func__, __LINE__);*(int*)0=0;}

struct colors {
    SDL_Color red = {255, 0, 0, 255};    // Red
    SDL_Color green = {0, 255, 0, 255};    // Green
    SDL_Color blue = {0, 0, 255, 255};    // Blue
    SDL_Color yellow = {255, 255, 0, 255};  // Yellow
    SDL_Color magenta = {255, 0, 255, 255};  // Magenta
    SDL_Color cyan = {0, 255, 255, 255};  // Cyan
    SDL_Color orange = {255, 165, 0, 255};  // Orange
    SDL_Color purple = {128, 0, 128, 255};  // Purple
    SDL_Color teal = {0, 128, 128, 255};// Teal
    SDL_Color gray = {0x80, 0x80, 0x80, 255}; // Gray
    SDL_Color white = {255, 255, 255, 255}; //white
};


#endif //UTIL_HPP_
