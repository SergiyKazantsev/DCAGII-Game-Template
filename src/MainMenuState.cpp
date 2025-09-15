#include "MainMenuState.hpp"
#include <iostream>

Color green = {173, 204, 96, 255};
Color black = {0, 0, 0, 255};

MainMenuState::MainMenuState()
{
}

void MainMenuState::init()
{
    std::cout << "You are in the Main Menu State" << std::endl;
    player.x = 200;
    player.y = 200;
    player.skip = false;
}

void MainMenuState::handleInput()
{
    if (IsKeyPressed(KEY_SPACE)) {
        player.vy = -300.0f;
        std::cout << "You entered ESPACIO "; 
    }
}

void MainMenuState::update(float deltaTime)
{ 
    this->handleInput();
    player.vy += 686.0f * deltaTime;
    player.y += player.vy * deltaTime;
    std::cout << "player X:" << player.x << ", player Y: " << player.y << ", player VY: " << player.vy << "Delta time: "<< deltaTime << "\n";
}

void MainMenuState::render()
{
    BeginDrawing();
    ClearBackground(green);
    if (!player.skip) {
        DrawText("Bienvenido a\nFlappy Bird DCA\nPulsa ESPACIO", 60, 200, 21, black);
        if (IsKeyPressed(KEY_SPACE)) {
            player.skip = true;
            player.x = 200;
            player.y = 200;
        }
    } else {
        DrawCircle(player.x, player.y, 17, RED);
    }
    EndDrawing();  
}