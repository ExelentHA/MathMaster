/*
TODO: Lazy Assert.. Change to proper error handling
 */


#include "Sound.hpp"

Sound::Sound()
{
    Init();
    hasSound = false;
}

Sound::~Sound()
{
    Close();
}

// LOG: Made a separate Load Function. THIS IS AN INIT FUNCTION GAHD DARN IT!!
void Sound::Init()
{
  if(!MIX_Init())
    std::cerr << "MIX_Init Error: " << SDL_GetError() << std::endl;

  // create mixer obj
  mixer = MIX_CreateMixerDevice(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, nullptr); 
  if(mixer == nullptr)
        std::cerr << "MIX_CreateMixerDevice Error: " << SDL_GetError() << std::endl;
}

void Sound::Load_Audio(const char *path)
{
  // Load the audio inside the mixer
  sound = MIX_LoadAudio(mixer, path, 1);
  if(sound == nullptr)
  {
    std::cerr << "MIX_LoadAudio Error: " << SDL_GetError() << std::endl; 
  }
}

void Sound::Create_Track()
{
  // create a handle to those audio
  MIX_CreateTrack(mixer);
}

bool Sound::Check()
{
  return hasSound;
}

bool Sound::CheckPlaying()
{
  return MIX_TrackPlaying(track);
}

void Sound::Stop()
{
  assert(MIX_StopTrack(track, 0) == 0);
}

void Sound::Play()
{
  assert(MIX_PlayTrack(track, 0) == 0);
}

void Sound::Close()
{
  MIX_Quit();
  // MIX_DestroyMixer(mixer); // Destroy The Mixer
}
