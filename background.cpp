#include <iostream>
#include <cmath>

#include <SDL.h>
#include <SDL_image.h>
#include "Grahics.h"
#include "Defs.h"
#include "background.h"

using namespace std;

double offsetX1 = 0;
double offsetX2 = 0;
double offsetSky = 0;

void scrollingLeftForest(const double v, Graphics graphics, SDL_Texture* LeftForest) {

    graphics.renderTexture(LeftForest, 0, 50, 274, 661, offsetX1, (14310-27*offsetX1)/53.0, 530-19*offsetX1/53.0, 1280-50*offsetX1/53.0);
    offsetX1+=v;
    //cerr << offsetX1 << '\n';
    offsetX1+=(530-offsetX1)*0.001;
    if(offsetX1>=530.0) offsetX1-=530.0;
}

void scrollingRightForest(const double v, Graphics graphics, SDL_Texture* RightForest) {
    graphics.renderTexture(RightForest, width-274, 70, 274, 661, -offsetX2/2+260, -5.0/13*offsetX2+200, -offsetX2/2 +520,-57.0/52*offsetX2+1140);
    offsetX2+=v;
    offsetX2+=(520-offsetX2)*0.001;
    if(offsetX2>=520.0) offsetX2-=520.0;
}

void scrollingSky(Graphics graphics,SDL_Texture* Sky) {
    graphics.renderTexture(Sky,0,0,width,290,0,offsetSky,2480,580);
    offsetSky+=1;
    if(offsetSky>=580) offsetSky-=580;
}

