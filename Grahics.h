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

    void renderTexture(SDL_Texture *image, const double x, const double y, const double w, const double h, const double cx, const double cy, const double cw, const double ch);

    void renderTexture(SDL_Texture *image, const double x, const double y, const double w, const double h);

    void renderTexture(SDL_Texture *image, const double x, const double y);

    void presentScene();

    void quit();


};

void TurnRight(int &x, const int v);

void TurnLeft(int &x,const int v);

void Up(int &y, const int v);

void Down(int &y, const int v);



#endif

