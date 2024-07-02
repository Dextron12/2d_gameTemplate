
#include "Window.hpp"
#include "Player.hpp"
#include "ResourceManager.hpp"

#include "Windows.h"



int main(int argc, char** argv){
    Events window("Untitled Game", 800, 600);
    Player player(300, 300, 32, 32);
    player.m_Velocity = 8;

    Filesystem fs;
    Textures text;
    Fonts font;

    font.loadFont("Chiller", fs.getPath("Library/Fonts/CHILLER.TTF"), 24);
    font.loadFont("PlayBill", fs.getPath("Library/Fonts/PLAYBILL.TTF"), 24);
    font.loadFont("Arial", fs.getPath("Library/Fonts/ARIALN.TTF"), 16);

    text.loadTexture(&window, "Brick", fs.getPath("Library/Textures/brick_wall.jpg"));
    SDL_Rect texPos = {0,0,800,600};

    while (window.windowState){
        SDL_SetRenderDrawColor(window.renderer, 100, 149, 237, 255);
        SDL_RenderClear(window.renderer);

        window.updateEvents();

        text.renderTexture(&window, "Brick", SDL_Rect{0,0, 200, 200});
        font.renderText(&window, "Hello there, My name is Billy boy.", "PlayBill", SDL_Rect{0, 0, 0,0}, SDL_Colour{0, 0, 0, 255});
        font.renderText(&window, "Ain't I just the scariest bit of text out there!", "Chiller", SDL_Rect{400,300,0,0}, SDL_Colour{0, 0, 0, 255});
        font.renderText(&window, "Lorem ipsum dolar sit", "Arial", SDL_Rect{25,300,0,0}, SDL_Colour{0,255,0255});

        player.update(&window);

        if (window.m_keyEsc){
            window.windowState = false;
        }

        window.flushEvents();
        SDL_RenderPresent(window.renderer);
    }

    return 0;
}
