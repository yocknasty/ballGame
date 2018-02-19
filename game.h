#ifndef BALL_GAME_H
#define BALL_GAME_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

class Game 
{
    public:Game();
    void run();
    
    private:
        void processEvents();
        void update(sf::Time deltaTime);
        void render();
        void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
    private:
        
        sf::RenderWindow mWindow;
        sf::Sprite mPlayer;
        sf::Texture mTexture;
        bool isMovingUp;
        bool isMovingDown;
        bool isMovingLeft;
        bool isMovingRight;
        

};

#endif // BALL_GAME_H



