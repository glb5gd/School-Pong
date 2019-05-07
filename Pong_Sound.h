#ifndef PONG_SOUND_H
#define PONG_SOUND_H

class Sound : public Abstract_Object
{
  public:
    virtual ~Sound();

    Sound(const string & name, const string & file_name);

    virtual void obj_main(vector<Abstract_Object*> & obj_list, SDL_Renderer* const & renderer, SDL_Event & e);

  private:
    Mix_Chunk* m_sound{nullptr};
};

#endif