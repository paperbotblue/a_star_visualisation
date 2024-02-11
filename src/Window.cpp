#include "./../inc/Window.hpp"
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>

Window::Window(char* window_title, unsigned int window_height, unsigned int window_width, SDL_Color window_bg_color)
{
  SDL_Init(SDL_INIT_VIDEO);
  window = SDL_CreateWindow(window_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, window_width, window_height, SDL_WINDOW_SHOWN); 
  ASSERT(window != nullptr);
  renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
  ASSERT(renderer != nullptr);
  
  this->window_height = window_height;
  this->window_width = window_width;
  this->window_title = window_title;
  this->window_bg_color = window_bg_color; 
}

void Window::render_window() 
{
  SDL_SetRenderDrawColor(this->renderer, this->window_bg_color.r, this->window_bg_color.g, this->window_bg_color.b, this->window_bg_color.a);
  SDL_RenderPresent(this->renderer);
  SDL_RenderClear(this->renderer);
}

SDL_Renderer* Window::get_renderer() {return this->renderer;}
unsigned int Window::get_window_width() {return this->window_width;}
unsigned int Window::get_window_height() {return this->window_height;}

Window::~Window()
{
  SDL_DestroyRenderer(this->renderer);
  SDL_DestroyWindow(this->window);
  this->window = nullptr;
  this->renderer = nullptr;
}
