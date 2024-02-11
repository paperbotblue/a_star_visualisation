#include "./../inc/Main.hpp"
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_mouse.h>
Main::Main()
{
  this->window = new Window("Graph",700 , 1000,this->color.gray); 
  this->running = true;
  this->grid = new Grid(window->get_window_height(), window->get_window_width());     
  this->text.create_font("/sharedDrive/Project/graphv2/res/arial.ttf", 10);
  this->a_star = new A_star(SECTOR_SIZE, grid->get_walls());
  this->lol = false;
}

Main::~Main()
{
  
}

void Main::run()
{
  while(running)
  {
    SDL_GetMouseState(&this->mouse_pos.x, &this->mouse_pos.y);
    if (SDL_PollEvent(&this->event) > 0) 
    {
      if(event.type == SDL_QUIT)
      {
        this->running = false;
      }
      event_loop();
    }
    game_loop();
    window->render_window();
  }
}

void Main::game_loop()
{
  grid->render_grid(window->get_renderer(), mouse_pos);
  text.render_fonts(window->get_renderer());
  a_star->render_shit(window->get_renderer());
}

void Main::event_loop()
{
  if(event.type == SDL_KEYDOWN)
  {
    switch(event.key.keysym.sym)
    {
      case SDLK_0:
        grid->set_wall();
        break;
      case SDLK_1:
        if(!grid->check_player_flag())
        {
          grid->set_player();
          this->text.create_text(window->get_renderer(), "P", color.white, 
                                {grid->get_mouse_calibrated_position().x, grid->get_mouse_calibrated_position().y,SECTOR_SIZE, SECTOR_SIZE});
          a_star->set_src(grid->get_mouse_calibrated_position());
        }
        break;
      case SDLK_2:
        if(!grid->check_destination_flag())
        {
          grid->set_destination();
          this->text.create_text(window->get_renderer(), "H", color.white, 
                                {grid->get_mouse_calibrated_position().x, grid->get_mouse_calibrated_position().y,SECTOR_SIZE, SECTOR_SIZE});
          a_star->set_dist(grid->get_mouse_calibrated_position());
        }
        break;
      case SDLK_a:
        a_star->execuate();

        lol = true;
        break;
    }
  }
  else if(event.type == SDL_KEYUP)
  {
    switch(event.key.keysym.sym)
    {

    }
  }
}
