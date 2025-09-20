#include "GameOverState.hpp"
#include <iostream>

GameOverState::GameOverState()
{
}

void GameOverState::init()
{
    std::cout << "You are in the Game Over State" << std::endl;

}

void GameOverState::handleInput()
{

}

void GameOverState::update(float deltaTime)
{ 
    
}

void GameOverState::render()
{
    BeginDrawing();
    ClearBackground(GREEN);
    DrawText("GAME OVER\nPulsa ESPACIO", 60, 200, 21, BLACK);
    EndDrawing();  
}