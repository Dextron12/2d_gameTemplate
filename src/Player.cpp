
#include "Player.hpp"

Player::Player(Point_2D Position, Point_2D Size){
    m_Position = Position;
    m_Size = Size;
}

Player::Player(int posX, int posY, int sizeW, int sizeH){
    m_Position.x = posX; m_Position.y = posY;
    m_Size.x = sizeW; m_Size.y = sizeH;
}

void Player::update(Events* window){

    if (window->m_keyW == true){
        m_Position.y -= m_Velocity * window->deltaTime;
        //std::cout << "going up" << std::endl;
    } else if (window->m_keyA == true) {
        m_Position.x -= m_Velocity * window->deltaTime;
        //std::cout << "going left" << std::endl;
    } else if (window->m_keyS == true){
        m_Position.y += m_Velocity * window->deltaTime;
        //std::cout << "going down" << std::endl;
    } else if (window->m_keyD == true){
        m_Position.x += m_Velocity * window->deltaTime;
        //std::cout << "going right" << std::endl;
    }

    draw(window);
}

void Player::draw(Events* window){
    drawDebugBody(window->renderer);
}