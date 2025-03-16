#include <SDL.h> 
#include <vector>
#include "Kernel.h"

using namespace std;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window* win = NULL;
SDL_Renderer* renderrer = NULL;

int init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        return 1;
    }

    win = SDL_CreateWindow("Lab2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (win == NULL) {
        return 1;
    }

    renderrer = SDL_CreateRenderer(win, -1,SDL_RENDERER_ACCELERATED);
    if (renderrer == NULL) {
        return 1;
    }

    return 0;
}


void quit() {


    SDL_DestroyWindow(win);

    SDL_Quit();
}

void render(vector<Drawnable*> objects, SDL_Renderer* rend) {

    SDL_RenderClear(rend);

    for (Drawnable * ob : objects) {
        (*ob).Draw(rend);
    }


    SDL_RenderPresent(rend);
}

int main(int argc, char** args) {

    if (init() == 1) {
        return 1;
    }



    int vel = 3;

    SDL_Event e;

    Trace tracer;

    Kernel ker(200,11,50,50, vel, renderrer,&tracer );

    vector<Drawnable *> objs;
    objs.push_back(&ker);

    while (true) {

        SDL_Delay(10);

        SDL_PollEvent(&e);

        
        if (e.type == SDL_KEYDOWN) {
            if (e.key.keysym.sym == SDLK_q) {
                break;
            }

            if (e.key.keysym.sym == SDLK_d) {
                ker.Right();
            }

            if (e.key.keysym.sym == SDLK_a) {
                ker.Left();
            }

            if (e.key.keysym.sym == SDLK_s) {
                ker.Down();
            
            }
            if (e.key.keysym.sym == SDLK_w) {
                ker.Up();
            }
        }

        render(objs, renderrer);
    }
    

    quit();

    return 0;
};