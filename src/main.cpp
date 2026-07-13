



SDL_Texture *LoadTexture(SDL_Renderer *renderer, const char *path);




int main(int argc, char *argv[])
{
    return 0;
}

SDL_Texture *LoadTexture(SDL_Renderer *renderer, const char *path)
{
    SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(renderer, path);
	if (texture == NULL)
		std::cout << "Failed to load texture. Error: " << SDL_GetError() << std::endl;
	return texture;
}
