#pragma once

#include <iostream>
#include <SDL3/SDL.h>

#include "Text.hpp"
#include "Timer.hpp"

class Clock
{
public:
    Clock();
    ~Clock();

    void Init(const char* path, int posx, int posy, float scale, SDL_Renderer *r);

    void Refresh();
    void SetTime(unsigned int ptime);
    void Reset();
    bool NoTime();
    void Update(SDL_Renderer *r);
    void Render(SDL_Renderer *renderer);
private:
    unsigned int time = 0, orgTime = 0;
  SDL_Color color {0xff, 0xff, 0xff, 0xff};
    Text text;
    Timer timer;
};
