#ifndef BALL_GAME_H
#define BALL_GAME_H
#include <SFML/Graphics.hpp>


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
        sf::CircleShape mPlayer;
        
        

};

#endif // BALL_GAME_H



