#include "./../inc/Text.hpp"
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_ttf.h>
#include <cstddef>

Text::Text()
{
  ASSERT(TTF_Init() == 0);
}

void Text::create_font( const char* font,unsigned int font_size)
{
  this->font = TTF_OpenFont(font, font_size); 
  ASSERT(this->font != nullptr);
}

void Text::create_text(SDL_Renderer* renderer, const char* text,SDL_Color color, SDL_Rect pos)
{
  this->surface = TTF_RenderText_Solid(this->font, text, color);
  ASSERT(this->surface != nullptr);
  create_texture(renderer ,pos);   
}

void Text::create_texture(SDL_Renderer* renderer, SDL_Rect pos)
{
  SDL_Texture* texture;
  texture = SDL_CreateTextureFromSurface(renderer, this->surface);
  ASSERT(texture != nullptr);
  text_textures.push_back(texture);
  text_coordinates.push_back(pos);
}

void Text::render_fonts(SDL_Renderer* renderer)
{
  for(size_t i = 0 ; i < text_textures.size() ; ++i)
  {
    SDL_RenderCopy(renderer, text_textures[i], nullptr, &text_coordinates[i]);
  }
}

Text::~Text()
{
  for(size_t i = 0 ; i < text_textures.size(); ++i)
  {
    SDL_DestroyTexture(text_textures[i]);
    text_textures[i] = nullptr;
  }
  text_coordinates.clear();
  SDL_FreeSurface(this->surface);
  TTF_CloseFont(this->font);
  TTF_Quit();
  this->surface = nullptr;
  this->font = nullptr;
}
