#include <SDL3/SDL.h>

#include <iostream>
#include <string>

#include "Page.h"
#include "Label.h"
#include "Button.h"
#include "GVector.h"
#include "Drawnable.h"

static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;

static Page* current_page = NULL;

/* This function runs once at startup. */
int Init_SDL()
{

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        return 1;
    }

    if (!SDL_CreateWindowAndRenderer("lab3", 640, 480, 0, &window, &renderer)) {

        return 1;
    }

    
    if (TTF_Init() == -1) {
        return 1;
    }

    return 0;
}


void print(void * a) {
    const char* originalStr = static_cast<const char*>(a);
    std::cout << originalStr << "\n";
}

void changePage(void *pg) {
    current_page = (Page*)pg;
    current_page->show();
}

void show_dialog(void * n) {
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,"warning!","Hellow!",window);
}

void quit() {


    SDL_DestroyWindow(window);

    SDL_Quit();
}

int main() {
    
    if (Init_SDL() == 1) {
        return 1;
    }

   

    Page pg( "one",renderer );

    current_page = &pg;

    Page pn( "two",renderer );



    GVector gv(100, 10);
    Label lb("Hello World", gv);

    GVector size(200, 30);

    GVector gv_m(250, 250);
    Button btn("Fud3",gv_m,size, changePage,(void *) &pn);

    GVector gv_6(0, 250);
    Button bt6("Show dialog", gv_6, size, show_dialog, (void*) NULL);

    GVector gv_p(250, 350);
    Button btn1("Fun43", gv_p,size, print, (void *)"123sagdsg4");

    Button back("BACK", gv_m, size, changePage, (void *)&pg);
    pn.addObject(&back);


    pg.addObject(&(lb));
    pg.addObject(&btn);
    pg.addObject(&btn1);
    pg.addObject(&bt6);

    current_page->show();
 
    SDL_Event e;

    while (true) {
        
        SDL_PollEvent(&e);

        current_page->holdEvents(&e);

        if (e.type == SDL_EVENT_QUIT) {
            break;
        }


    }

    quit();

    return 0;
}