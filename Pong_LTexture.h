#ifndef LTEXTURE_H
#define LTEXTURE_H

class LTexture
{
  public:
    //Initializes variables
    LTexture(){}

    //Deallocates memory
    ~LTexture();

    //Loads image at specified path
    const bool load_from_memory(SDL_Renderer* const & renderer, const char png_bytes[], const long & size);

    //Deallocates texture
    void free();
        
    //Set color modulation
    void set_color(const Uint8 & red, const Uint8 & green, const Uint8 & blue) const;
        
    //Set blending
    void set_blend_mode(const SDL_BlendMode & blending) const;

    //Set alpha modulation
    void set_alpha(const Uint8 & alpha) const;

    //Renders texture at given point
    void render(SDL_Renderer* const & renderer, const long & x, const long & y, const SDL_Rect* const & clip = NULL, const double & angle = 0.0, const SDL_Point* const & center = NULL, const SDL_RendererFlip & flip = SDL_FLIP_NONE) const;

    //Gets image dimensions
    inline const unsigned long get_width() const {return m_width;}
    inline const unsigned long get_height() const {return m_height;}

  private:
    //The actual hardware texture
    SDL_Texture* m_texture{nullptr};

    //Image dimensions
    long m_width{0};
    long m_height{0};
};

#endif