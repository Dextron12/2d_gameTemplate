#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Physics.hpp"
#include "Window.hpp"

class Player : public Body_2D{
    private:
        void draw(Events* window);
    public:
        Player(Point_2D Position, Point_2D Size);
        Player(int posX, int posY, int sizeW, int sizeH);

        void update(Events* window);
};

#endif