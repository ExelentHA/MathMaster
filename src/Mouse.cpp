#include "Mouse.hpp"
#include <cassert>
Mouse::Mouse(SDL_Renderer *renderer, const char *path)
{
    texture = IMG_LoadTexture(renderer, path);
    if(texture == nullptr)
        std::cerr << "Failed to load texture Error: " << SDL_GetError() << std::endl;
    dest.h = dest.w = 32;
    point.h = point.w = 1;
    assert(SDL_HideCursor() == true); // hide the cursor in the screen
}

Mouse::~Mouse()
{

}

void Mouse::update()
{
    SDL_GetMouseState(&dest.x, &dest.y);
    point.x = dest.x;
    point.y = dest.y;
}

SDL_Texture *Mouse::GetTexture()
{
    return texture;
}

void Mouse::Draw(SDL_Renderer *r)
{
    SDL_RenderTexture(r, texture, nullptr, &dest);
}
