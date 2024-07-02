#ifndef PHYSICS_HPP
#define PHYSICS_HPP

#include <SDL2\SDL.h>

struct Point_2D {
    int x;
    int y;
};



struct Body_2D{
    Point_2D m_Position;
    int      m_Velocity;

    Point_2D m_Size;

    //Converts BODY_2D data into a SDL_Rect
    SDL_Rect getRect(){
         SDL_Rect pos;
        pos.x = m_Position.x; pos.y = m_Position.y;
        pos.w = m_Size.x; pos.h = m_Size.y;
        return pos;
    }

    void drawDebugBody(SDL_Renderer* renderer){
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_Rect pos = getRect();
        SDL_RenderFillRect(renderer, &pos);
    }
};

#endif