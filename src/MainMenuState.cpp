#include "MainMenuState.hpp"
#include <iostream>

MainMenuState::MainMenuState()
{
}

void MainMenuState::init()
{
    std::cout << "You are in the Main Menu State" << std::endl;

}

void MainMenuState::handleInput()
{

}

void MainMenuState::update(float deltaTime)
{ 
    
}

void MainMenuState::render()
{
    BeginDrawing();
    ClearBackground(GREEN);
    DrawText("Bienvenido a\nFlappy Bird DCA\nPulsa ESPACIO", 60, 200, 21, BLACK);
    EndDrawing();  
}