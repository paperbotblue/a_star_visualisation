#ifndef GRID_HPP_
#define GRID_HPP_

#include <SDL2/SDL.h>
#include <SDL2/SDL_assert.h>
#include <SDL2/SDL_rect.h>
#include <vector>
#include <iostream>

#define SECTOR_SIZE 100

struct Line
{
  unsigned int x,y;
  unsigned int x1, y1; 
};

class Grid
{
  private:
    std::vector<Line> grid;
    std::vector<SDL_Point> walls;
    unsigned int grid_row_length;
    SDL_Point player;
    SDL_Point destination;
    SDL_Point mouse_calibrated_position;

    bool player_flag;
    bool destination_flag;
  public:
    Grid(unsigned int window_height, unsigned int window_width);
    void set_wall();
    std::vector<SDL_Point>* get_walls();
    void set_player();
    SDL_Point get_player();
    void set_destination();
    SDL_Point get_destination();
    bool check_player_flag();
    bool check_destination_flag();
    SDL_Point get_mouse_calibrated_position();
    void render_grid(SDL_Renderer* renderer, SDL_Point mouse_pos);
    ~Grid();
};

#endif // GRID_HPP_
