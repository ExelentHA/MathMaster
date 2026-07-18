#pragma once

#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3/SDL_image.h>

class Mouse
{
public:
    Mouse();
    ~Mouse();

    void update(); // updates positions
    SDL_Texture *GetTexture();
    void Init(SDL_Renderer *renderer, const char *path);
    void Draw(SDL_Renderer *r);
    SDL_FRect point; // use to inteact with button
private:
    SDL_Texture *texture;
    SDL_FRect dest;
};
