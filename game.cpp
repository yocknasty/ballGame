#include "game.h"

Game::Game()
    :mWindow(sf::VideoMode(640, 480), "ball game"), mPlayer()
    {
        mPlayer.setRadius(40.f);
        mPlayer.setPosition(100.f, 100.f);
        mPlayer.setFillColor(sf::Color::Red);
    }

void Game::run(){
    while (mWindow.isOpen()){
        processEvents();
        update();
        render();
    }
}

void Game::processEvents(){
    sf::Event event;
    while (mWindow.pollEvent(event)){
        switch (event.type){
            
        }
        if(event.type == sf::Event::Closed)
            mWindow.close();
    }
}

void Game::update(){

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