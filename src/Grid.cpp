#include "./../inc/Grid.hpp"
#include <SDL2/SDL_rect.h>

Grid::Grid(unsigned int window_height ,unsigned int window_width)
{
  grid_row_length = window_width/SECTOR_SIZE;
  for(unsigned int  i = 0 ; i < window_width ; i+=SECTOR_SIZE)
  {
    grid.push_back({i, 0, i, window_height});
  }
  for(unsigned int i = 0 ; i < window_height ; i+=SECTOR_SIZE)
  {
    grid.push_back({0, i, window_width, i});
  }
  player_flag = false;
  destination_flag = false;
}


void Grid::set_wall()
{
  for(size_t i = 0 ; i < walls.size() ; ++i)
  {
    if(walls[i].x == mouse_calibrated_position.x && walls[i].y == mouse_calibrated_position.y)
    {
      return;
    }
  }
  SDL_Point i = {mouse_calibrated_position.x,mouse_calibrated_position.y};
  walls.push_back(i);
}

std::vector<SDL_Point>* Grid::get_walls()
{
  return &walls;
}

void Grid::set_player()
{
  player = {mouse_calibrated_position.x, mouse_calibrated_position.y};
  player_flag = true;
}

SDL_Point Grid::get_player()
{
  return player;
}

void Grid::set_destination()
{
  destination = {mouse_calibrated_position.x, mouse_calibrated_position.y};
  destination_flag = true;
}

SDL_Point Grid::get_destination()
{
  return destination;
}

bool Grid::check_player_flag()
{
  return player_flag;
}

bool Grid::check_destination_flag()
{
  return destination_flag;
}

SDL_Point Grid::get_mouse_calibrated_position()
{
  return mouse_calibrated_position; 
}

void Grid::render_grid(SDL_Renderer* renderer,SDL_Point mouse_pos)
{ 
  mouse_pos.x = (mouse_pos.x / SECTOR_SIZE) * SECTOR_SIZE;
  mouse_pos.y = (mouse_pos.y / SECTOR_SIZE) * SECTOR_SIZE;
  mouse_calibrated_position = mouse_pos;

  SDL_SetRenderDrawColor(renderer,0xFF, 0xFF, 0xFF ,0xFF);
  
  for(size_t i = 0 ; i < grid.size(); ++i)
  {
    SDL_RenderDrawLine(renderer, grid[i].x, grid[i].y, grid[i].x1, grid[i].y1);
  }
  SDL_Rect r;
  SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
  for(unsigned int i = 0 ; i < walls.size() ; ++i)
  {
    r = {walls[i].x, walls[i].y, SECTOR_SIZE, SECTOR_SIZE};  
    SDL_RenderFillRect(renderer, &r);
  }
  r = {player.x, player.y, SECTOR_SIZE, SECTOR_SIZE};
  if(player_flag)
  {
    SDL_SetRenderDrawColor(renderer, 0x24, 0x0E, 0x88, 0xFF);
    SDL_RenderFillRect(renderer, &r);
  }
  if(destination_flag)
  {
    r = {destination.x, destination.y, SECTOR_SIZE, SECTOR_SIZE};
    SDL_SetRenderDrawColor(renderer, 0xF0, 0x43, 0x93, 0xFF);
    SDL_RenderFillRect(renderer, &r);
  }
}

Grid::~Grid()
{
  this->walls.clear();
  this->grid.clear();
}
