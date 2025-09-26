#include "MainMenuState.hpp"
#include <iostream>

MainMenuState::MainMenuState()
{
    this->score = 0;
}

void MainMenuState::init()
{
    std::cout << "You are in the Main Menu State" << std::endl;
    this->shouldSwitchState = false;

}

void MainMenuState::handleInput()
{

}

void MainMenuState::update(float deltaTime)
{ 
    if(IsKeyPressed(KEY_SPACE)) {
        this->shouldSwitchState = true;
    }
}

void MainMenuState::render()
{
    BeginDrawing();
    ClearBackground(GREEN);
    DrawText("Bienvenido a\nFlappy Bird DCA\nPulsa ESPACIO", 60, 200, 21, BLACK);
    EndDrawing();  
}