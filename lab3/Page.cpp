#include "Page.h"

void Page::show()
{

    const float red = 250;
    const float green = 250;
    const float blue = 250;
    SDL_SetRenderDrawColorFloat(_renderer, red, green, blue, SDL_ALPHA_OPAQUE_FLOAT);



    SDL_RenderClear(_renderer);

    for (Drawnable* ob : _objects) {
        (*ob).Draw(_renderer);
    }


    SDL_RenderPresent(_renderer);
}

void Page::addObject(Drawnable* obj)
{   
    _objects.push_back(obj);
}

void Page::holdEvents(SDL_Event *e)
{

    float x, y;
    SDL_GetMouseState(&x, &y);


    for (Drawnable* el : _objects)
    {
        

        if (el->GetType() == BUTTON) {

            Button* btn = (Button*)el;

            if (btn->inArea(x, y)) {

                if (e->type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
                    btn->ClickAction();
                }
                
            }

        }

    }


}
