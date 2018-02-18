#include "game.h"
const sf::Time TimePerFrame = sf::seconds(1.f/ 60.f);
const float PlayerSpeed = 100.f; 

Game::Game()
    :mWindow(sf::VideoMode(640, 480), "ball game"), mPlayer()
    {
        if(!mTexture.loadFromFile("/home/ajyockey/Projects/sfml_projects/Eagle.png"))
            std::cout << "****************Can't Load image******************";
        mPlayer.setTexture(mTexture);
        mPlayer.setPosition(100.f, 100.f);
       
        bool isMovingUp(false);
        bool isMovingDown(false);
        bool isMovingLeft(false);
        bool isMovingRight(false);
    }

void Game::run(){
    sf::Clock clock;
    sf::Time timeSinceUpdate = sf::Time::Zero;
    while (mWindow.isOpen()){
        sf::Time elapsedTime = clock.restart();
        timeSinceUpdate += elapsedTime;
        
        while (timeSinceUpdate > TimePerFrame){
            timeSinceUpdate -= TimePerFrame;
            processEvents();
            update(TimePerFrame);
        }
        render();
    }
}
void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed){
    if(key== sf::Keyboard::W)
        isMovingUp = isPressed;
    else if (key==sf::Keyboard::S)
        isMovingDown = isPressed;
    else if (key==sf::Keyboard::A)
        isMovingLeft = isPressed;
    else if (key==sf::Keyboard::D)
        isMovingRight = isPressed;
}

void Game::processEvents(){
    sf::Event event;
    while (mWindow.pollEvent(event)){
        switch (event.type){
            case sf::Event::KeyPressed:
                handlePlayerInput(event.key.code, true);
                break;

            case sf::Event::KeyReleased:
                handlePlayerInput(event.key.code, false);
                break;

            case sf::Event::Closed:
                mWindow.close();
                break;
        }
    }
}

void Game::update(sf::Time deltaTime){
    sf::Vector2f movement(0.f, 0.f);
    if(isMovingUp)
        movement.y -= PlayerSpeed;
    if(isMovingDown)
        movement.y += PlayerSpeed;
    if(isMovingLeft)
        movement.x -= PlayerSpeed;
    if(isMovingRight)
        movement.x += PlayerSpeed;
    
    mPlayer.move(movement * deltaTime.asSeconds());
}

void Game::render(){
    mWindow.clear();
    mWindow.draw(mPlayer);
    mWindow.display();

}

int main()
{
    Game game;
    game.run();
};