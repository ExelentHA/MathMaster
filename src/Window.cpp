#include "Window.hpp"

WindowRenderer::WindowRenderer()
{
  if(!SDL_Init(SDL_INIT_VIDEO) && !SDL_Init(SDL_INIT_AUDIO))
    {
        std::cerr << "SDL_VIDEO and SDL_AUDIO Error: " << SDL_GetError() << std::endl; 
    }
}

WindowRenderer::~WindowRenderer()
{ }

void WindowRenderer::create(const char* title, int Width, int Height)
{
    window = SDL_CreateWindow(title, Width, Height, 0);
    if(window == nullptr){
        std::cerr << "Failed to Create window Err: " << SDL_GetError() << std::endl;
    }
    renderer = SDL_CreateRenderer(window, nullptr);
    if(renderer == nullptr)
    {
        std::cerr << "Failed to create renderer Err: " << SDL_GetError() << std::endl;
    }
    SDL_SetRenderDrawColor(renderer, 255, 199, 0, 255); // default bg color
}

void WindowRenderer::loadImage(const char *path)
{
    // load a texture
    SDL_Surface *img = IMG_Load(path);
    if(img == nullptr)
        std::cerr << "IMG_Load() Error: " << SDL_GetError() << std::endl;
    texture = IMG_LoadTexture(renderer, path);
    SDL_DestroySurface(img); // clear Img buffer
    if(texture == nullptr)
        std::cerr << "IMG_LoadTexture() Error: " << SDL_GetError() << std::endl;
}

void WindowRenderer::clear()
{
    SDL_RenderClear(renderer);
}

void WindowRenderer::present()
{
    SDL_RenderPresent(renderer);
}

void WindowRenderer::render(SDL_Texture *t,int posx, int posy, int offsetx, int offsety, int size)
{ 
    SDL_FRect dst;
	SDL_GetTextureSize(t, &dst.w, &dst.h);

	dst.x = posx + offsetx/size;
	dst.y = posy + offsety/size;
	dst.w = dst.w/size;
	dst.h = dst.h/size;

    // render
    if(!SDL_RenderTexture(renderer, t, nullptr, &dst))
        std::cerr << "SDL_RenderTexture() Error: " << SDL_GetError() << std::endl;
}

void WindowRenderer::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}


