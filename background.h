#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Grahics.h"
#include "Defs.h"

using namespace std;

void scrollingLeftForest(const double v,Graphics graphics ,SDL_Texture* LeftForest);

void scrollingRightForest(const double v, Graphics graphics, SDL_Texture* RightForest);

void scrollingSky(Graphics graphics,SDL_Texture* Sky);

struct ScrollingBackground {
    SDL_Texture *texture;
    double offsetX = 0;
    double SPD = 2;
    double sclae = 1;
    double scaleSPD = 0.02;
    double h,w;

};
