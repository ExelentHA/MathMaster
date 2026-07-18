#pragma once

#include <iostream>
#include <memory>
#include <SDL3/SDL.h>

#include "Text.hpp"
#include "Timer.hpp"
#include "Button.hpp"
// #include "Sound.hpp" // Remove Temp.

class TextBox : public Button
{
public:
    TextBox();
    ~TextBox();

    void Init(const char *path,int posx, int posy, float pscale, SDL_Renderer *r, bool interactive);
    
    void Refresh();
    void SetRenderSpeed(float seconds);
    void RenderDynamic(SDL_Renderer *renderer); // set the text dinamically on the screen
    void Update(SDL_Renderer *r);
    void RenderStatic(SDL_Renderer *renderer);
    void SetText(std::string ptext);
    void Enable(bool set);
private:
    // void LoadSound(const char *path);
    // Sound s;

    std::unique_ptr<Timer> timer = std::make_unique<Timer>(); // std::unique_ptr<typename T> deletes the objest automatically
    Text text;
    std::string t, orgT;
    SDL_Color color {0xcc, 0xda, 0xd7, 0xff};
    int x, y, offx, offy, index;
    float scale, seconds;
    bool isButton, isEnable;
};
