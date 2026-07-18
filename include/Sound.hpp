#pragma once

#include <iostream>
#include <cassert>
#include <SDL3/SDL.h>
#include <SDL3/SDL_mixer.h>

class Sound
{
public:
  Sound();
  ~Sound();
    
  void Init();
  bool Check();
  void Load_Audio(const char *path);
    // can add pause functionality (TO_IMPLEMENT)
  void Create_Track();
  bool CheckPlaying();
  void Stop();
  void Play();
  void Close();
private:
  MIX_Mixer *mixer; // An opaque object that represents a mixer. Handles Everything
  MIX_Audio *sound; // An opaque object that represents audio data. Loads the Audio to the mixer 
  MIX_Track *track; // An opaque object that represents a source of sound output to be mixed. It is the control of the playbacks(stop, pause, play)

  bool hasSound; // what exactly this flag is used?
};

