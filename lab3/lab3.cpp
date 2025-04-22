#include <iostream>
#include <SDL3/SDL.h>
#include <sstream>
#include <fstream>

#include <string>

#include "Page.h"
#include "Label.h"
#include "Button.h"
#include "GVector.h"
#include "Drawnable.h"
#include "Dialog.h"
#include "NaviagetButton.h"
#include "DialogButton.h"

static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;

static Page* current_page = NULL;

using namespace std;

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

vector<vector<vector<string>>> parse_file(string input) {

    //string input = "[[[main],[sub]],[[Warning,Hi]],[[0,100,100,Hello World!]],[[0,100,400,Sub,0,1],[1,100,200,Back,0,0],[0,400,200,Dialog,1,0]]]";

    vector<vector<vector<string>>> result;

    istringstream iss(input);

    char ch;

    iss >> ch;

    while (iss >> ch && ch != ']') {


        vector<vector<string>> innerBlock;

        while (iss >> ch && ch != ']') {


            vector<string> pair;
            string item;

            while (iss >> ch && ch != ']') {
                if (ch == ',') {
                    pair.push_back(item);
                    item.clear();
                }
                else {
                    item += ch;
                }
            }

            if (!item.empty()) {
                pair.push_back(item);
            }

            innerBlock.push_back(pair);

            if (iss.peek() == ',') {
                iss >> ch;
            }
        }

        result.push_back(innerBlock);

        if (iss.peek() == ',') {
            iss >> ch;
        }
    }

    return result;
}


string getDataString() {
    string line;
    string result;
    ifstream in("data.int"); // окрываем файл для чтения
    while (std::getline(in, line)){
        result += line;
    }
    in.close();     // закрываем файл

    return result;
}


void create_pages_from_data(vector<vector<vector<string>>> * parsed, vector<Page> * pages, vector <Dialog> * dialogs, vector <Drawnable*> * objects) {
    

    GVector size(200, 30);

    auto pages_parse = parsed->at(0);
    for (auto p : pages_parse) {
        pages->emplace_back(p.at(0), renderer);
    }

    auto dialogs_parse = parsed->at(1);

    for (auto d : dialogs_parse) {
        dialogs->emplace_back(d.at(0), d.at(1));
    }


    auto lables_parse = parsed->at(2);
    for (auto & p : lables_parse) {

        objects->push_back(new Label(p.at(3), GVector(stoi(p.at(1)), stoi(p.at(2)))));
        pages->at(stoi(p.at(0))).addObject(objects->back());
    }

    auto buttons_parse = parsed->at(3);
    for (auto & p : buttons_parse) {

        if (stoi(p.at(4)) == 0) {
            objects->push_back(new NaviagetButton(p.at(3), GVector(stoi(p.at(1)), stoi(p.at(2))), size, &current_page, pages, stoi(p.at(5))));
            pages->at(stoi(p.at(0))).addObject(objects->back());
        }
        else if (stoi(p.at(4)) == 1) {
            objects->push_back(new DialogButton(p.at(3), GVector(stoi(p.at(1)), stoi(p.at(2))), size, dialogs, stoi(p.at(5))));
            pages->at(stoi(p.at(0))).addObject(objects->back());
        }

    }
}


void quit(SDL_WindowID id) {
    SDL_DestroyWindow(SDL_GetWindowFromID(id));

}

int main() {
    


    if (Init_SDL() == 1) {
        return 1;
    }

    vector<Page> pages;
    vector <Dialog> dialogs;
    vector <Drawnable*> objects;

    string data_string = getDataString();
    //auto parsed = parse_file("[\n[['main'],['sub']],\n[['Warning','Hi']],\n[[0,100,100,'Hello World!']],\n[[0,100,400,'Sub',0,1],[1,100,200,'Back',0,0],[0,400,200,'Dialog',1,0]]]");
    auto parsed = parse_file(data_string);
    cout << data_string;

    create_pages_from_data(&parsed,&pages,&dialogs, &objects);


    current_page = &(pages.at(0));

      
    current_page->show();
 
    SDL_Event e;

    while (true) {
        
        SDL_PollEvent(&e);

        current_page->holdEvents(&e);
         

        if (e.type == SDL_EVENT_WINDOW_CLOSE_REQUESTED)
        {
          
            if (e.window.windowID == SDL_GetWindowID(window)) {
                break;
            }
            quit(e.window.windowID);
        }

    }

    for (auto obj : objects) {
        delete obj;
    }

    SDL_Quit();

    return 0;
}