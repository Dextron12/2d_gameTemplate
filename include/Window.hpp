
#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <iostream>

#include <SDL2\SDL.h>
#include <SDL2\SDL_image.h>
#include <SDL2\SDL_ttf.h>

class Window{
    protected:
        Window(const char* windowTitle, int windowWidth, int windowHeight);
        ~Window();
    private:
        const char* windowTitle;
        int windowWidth, windowHeight;
        

    public:
        SDL_Window* window;
        SDL_Renderer* renderer;

        bool windowState = true;

        double deltaTime;

        SDL_Renderer* getRenderer(){
            return renderer;
        }
};


class Events : public Window {
    private:
        SDL_Event event;

        //private deltaTime vars for calcualtions;
        Uint64 LAST, NOW;
        

    public:

        Events(const char* wTitle, int wWidth, int wHeight);

        void updateEvents();
        void flushEvents(); //Flushes event stack

        //event vars
        bool m_keyEsc = false;

        //key vars

        //WASD Keys
        bool m_keyW = false;
        bool m_keyA = false;
        bool m_keyS = false;
        bool m_keyD = false;

        //Arrow keys
        bool m_keyUp = false;
        bool m_keyDown = false;
        bool m_keyRight = false;
        bool m_keyLeft = false;



};

#endif