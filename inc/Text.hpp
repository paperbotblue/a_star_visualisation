#ifndef TEXT_HPP_
#define TEXT_HPP_ 

#include <SDL2/SDL.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_ttf.h>
#include <vector>

#include "./Util.hpp"

class Text
{
  private:
    SDL_Surface* surface;
    TTF_Font* font;
    std::vector<SDL_Texture*> text_textures;
    std::vector<SDL_Rect> text_coordinates;

    void create_texture(SDL_Renderer* renderer,SDL_Rect pos);
  public:
    Text();
    void create_font( const char* font,unsigned int font_size);
    void create_text(SDL_Renderer* renderer, const char* text,SDL_Color color, SDL_Rect pos);
    void render_fonts(SDL_Renderer* renderer);
    ~Text();
};

#endif // !TEXT_HPP_
