#include <iostream>
#include <cmath>

#include <SDL.h>
#include <SDL_image.h>
#include "Grahics.h"
#include "Defs.h"
#include "background.h"

using namespace std;

const string Ground[6] = {
    graphics.loadTexture("imgs/background/ground.png"),
    graphics.loadTexture("imgs/background/ground.png"),
    graphics.loadTexture("imgs/background/ground.png"),
    graphics.loadTexture("imgs/background/ground.png"),
    graphics.loadTexture("imgs/background/ground.png"),
    graphics.loadTexture("imgs/background/ground.png")
};

void waitUntilKeyPressed()
{
    SDL_Event e;
    while (true) {
        if (SDL_PollEvent(&e) != 0 && (e.type == SDL_KEYDOWN || e.type == SDL_QUIT))
            return;
        SDL_Delay(10);
    }
}
int main(int argc, char* argv[])
{



    Graphics graphics;
    graphics.init();


    SDL_Texture* LeftForest = graphics.loadTexture("imgs/background/LeftForestFixed2.png");
    SDL_Texture* RightForest = graphics.loadTexture("imgs/background/RightForest.png");
    SDL_Texture* Top = graphics.loadTexture("imgs/background/Top_2.png");
    SDL_Texture* Ground = graphics.loadTexture("imgs/background/ground.png");
    SDL_Texture* Sky = graphics.loadTexture("imgs/background/SKY.png");
    SDL_Texture* BocPhai = graphics.loadTexture("imgs/background/BocPhai.png");
    SDL_Texture* Blur = graphics.loadTexture("imgs/background/Blur.png");
    /*graphics.prepareScene(background);
    graphics.presentScene();*/
    int x = 0;
    int y = 50;
    int Tick1, Tick2;
    const int v = 1;
    bool quit =0;
    const Uint8* Keypressed;
    SDL_Event event;
    double SPD,SPD0=1;
    long long Score = 0;
    bool movingRight = false, movingLeft = false, movingUp = false, movingDown = false;
    while (!quit) {
        Tick1 = SDL_GetTicks();
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    quit = true;
                    break;
                case SDL_KEYDOWN:
                    if (event.key.keysym.sym == SDLK_RIGHT) movingRight = true;
                    if (event.key.keysym.sym == SDLK_LEFT) movingLeft = true;
                    if (event.key.keysym.sym == SDLK_UP) movingUp = true;
                    if (event.key.keysym.sym == SDLK_DOWN) movingDown = true;
                    break;
                case SDL_KEYUP:
                    if (event.key.keysym.sym == SDLK_RIGHT) movingRight = false;
                    if (event.key.keysym.sym == SDLK_LEFT) movingLeft = false;
                    if (event.key.keysym.sym == SDLK_UP) movingUp = false;
                    if (event.key.keysym.sym == SDLK_DOWN) movingDown = false;
                    break;
            }
        }

        // 🔹 Cập nhật vị trí liên tục, không phụ thuộc vào sự kiện
        if (movingRight) TurnRight(x, v);
        if (movingLeft) TurnLeft(x, v);
        if (movingUp) Up(y, v);
        if (movingDown) Down(y, v);

        Score++;
        SPD = SPD0 + sqrt(static_cast<double>(Score))/100;
        cerr << SPD << '\n';

        scrollingSky(graphics,Sky);
        graphics.renderTexture(Ground,0,0);
        scrollingLeftForest(SPD,graphics,LeftForest);
        scrollingRightForest(SPD,graphics,RightForest);
        //graphics.renderTexture(BocPhai,width-274-10,210,10,90);
        graphics.renderTexture(Top,0,0);
        graphics.renderTexture(Blur,0,0);


        graphics.presentScene();
        SDL_RenderClear(graphics.renderer);

        /*graphics.renderTexture(RightForest, width-274, 50, 274, 661, 260, 200, 520, 1140);
        graphics.presentScene();
        SDL_Delay(1000);
        SDL_RenderClear(graphics.renderer);
        graphics.renderTexture(RightForest, width-274, 50, 274, 661, 0, 0, 260, 570);
        graphics.presentScene();
        SDL_Delay(1000);*/

        // 🔹 Vẽ lại nhân vật
        /*graphics.prepareScene(background);
        graphics.renderTexture(Knight, x, y, 336, 180);
        graphics.presentScene();
        */
        Tick2 = SDL_GetTicks();
        if (Tick2 - Tick1 < 1000 / FPS) {
            SDL_Delay(1000 / FPS - (Tick2 - Tick1));
        }
    }

    return 0;
}
