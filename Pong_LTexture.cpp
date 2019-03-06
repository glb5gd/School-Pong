#include "Pong_Main.h"

LTexture::~LTexture()
{
  //Deallocate
  free();
}

const bool LTexture::load_from_memory(SDL_Renderer* const & renderer, const char png_bytes[], const long & size)
{
  //Get rid of preexisting texture
  free();

  //The final texture
  SDL_Texture* new_texture{nullptr};

  //Load image at specified path
  SDL_Surface* loaded_surface{IMG_Load_RW(SDL_RWFromConstMem(png_bytes, size), 0)};
  if(loaded_surface == nullptr)
  {
    printf("Unable to load image! SDL_image Error: %s\n", IMG_GetError());
  }
  else
  {
    //Color key image
    SDL_SetColorKey(loaded_surface, SDL_TRUE, SDL_MapRGB(loaded_surface->format, 0, 0xFF, 0xFF));

    //Create texture from surface pixels
    new_texture = SDL_CreateTextureFromSurface(renderer, loaded_surface);
    if(new_texture == nullptr)
    {
      printf("Unable to create texture! SDL Error: %s\n", SDL_GetError());
    }
    else
    {
      //Get image dimensions
      m_width = loaded_surface->w;
      m_height = loaded_surface->h;
    }

    //Get rid of old loaded surface
    SDL_FreeSurface(loaded_surface);
  }

  //Return success
  m_texture = new_texture;
  return m_texture != nullptr;
}

void LTexture::free()
{
  //Free texture if it exists
  if(m_texture != nullptr)
  {
    SDL_DestroyTexture(m_texture);
    m_texture = nullptr;
    m_width = 0;
    m_height = 0;
  }
}

void LTexture::set_color(const Uint8 & red, const Uint8 & green, const Uint8 & blue) const
{
  //Modulate texture
  SDL_SetTextureColorMod(m_texture, red, green, blue);
}

void LTexture::set_blend_mode(const SDL_BlendMode & blending) const
{
  //Set blending function
  SDL_SetTextureBlendMode(m_texture, blending);
}

void LTexture::set_alpha(const Uint8 & alpha) const
{
  //Modulate texture alpha
  SDL_SetTextureAlphaMod(m_texture, alpha);
}

void LTexture::render(SDL_Renderer* const & renderer, const long & x, const long & y, const SDL_Rect* const & clip, const double & angle, const SDL_Point* const & center, const SDL_RendererFlip & flip) const
{
  //Set rendering space and render to screen
  SDL_Rect render_quad = {x, y, m_width, m_height};
    
  //Set clip rendering dimensions
  if(clip != nullptr)
  {
    render_quad.w = clip->w;
    render_quad.h = clip->h;
  }

  //Render to screen
  SDL_RenderCopyEx(renderer, m_texture, clip, &render_quad, angle, center, flip);
}