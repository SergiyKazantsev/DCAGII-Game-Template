#include "GameOverState.hpp"
#include <iostream>

GameOverState::GameOverState()
{
    this->score = 0;
}

void GameOverState::init()
{
    //std::cout << "You are in the Game Over State" << std::endl;
    this->shouldSwitchState = false;

}

void GameOverState::handleInput()
{

}

void GameOverState::update(float deltaTime)
{ 
    if(IsKeyPressed(KEY_R)) {
        this->shouldSwitchState = true;
    }
}

void GameOverState::render()
{
    BeginDrawing();
    ClearBackground(RED);
    std::string text = "Puntuación: " + std::to_string(score);
    DrawText(text.c_str(), 60, 360, 30, DARKBLUE);
    DrawText("GAME OVER\nPulsa R", 60, 200, 21, BLACK);
    EndDrawing();  
}