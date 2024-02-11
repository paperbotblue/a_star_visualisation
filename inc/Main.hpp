#ifndef MAIN_HPP_
#define MAIN_HPP_

#include <SDL2/SDL_events.h>
#include "./Window.hpp"
#include "./Grid.hpp"
#include "./Text.hpp"
#include "./A_star_algorithm.hpp"

class Main
{
  private:
    Window* window;
    Grid* grid;
    A_star* a_star;
    Text text;
    colors color; 
    bool running;
    bool lol;
    SDL_Event event;
    SDL_Point mouse_pos;
  public:

    void run();
    void event_loop();
    void game_loop(); 
    Main();
    ~Main();  

};



#endif // MAIN_HPP_
