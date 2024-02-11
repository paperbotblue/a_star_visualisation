#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include <SDL2/SDL.h>
#include "Util.hpp"

class Window
{
  private:
    unsigned int window_height; 
    unsigned int window_width;
    char* window_title;
    SDL_Color window_bg_color;

    SDL_Window* window;
    SDL_Renderer* renderer;
  public:
    Window(char* window_title, unsigned int window_height, unsigned int window_width, SDL_Color window_bg_color);

    void render_window();    
    SDL_Renderer* get_renderer();
    unsigned int get_window_width();
    unsigned int get_window_height();

    ~Window();
};

#endif
