#ifndef GRAPHICS_H
#define GRAPHICS_H
#include <SDL.h>
#include <SDL_image.h>
#include "Defs.h"
#include <iostream>

struct Graphics {
    SDL_Window* gwindow;
    SDL_Renderer* renderer;
    SDL_Texture* texture;
    const char *title = "Thử Đồ Họa";
    bool fullscr = 0;

    void LogErrAndExit(const char *msg, const char *err);

    void init();

    SDL_Texture *loadTexture(const char *filename);


    void prepareScene(SDL_Texture *background);

    void renderTexture(SDL_Texture *image, const int x, const int y, const int w, const int h);

    void presentScene();

    void quit();


};

#endif

