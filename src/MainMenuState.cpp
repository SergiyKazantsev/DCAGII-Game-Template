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

    spawnTimer += deltaTime;
    if(spawnTimer >= spawnEvery && player.skip) {
        spawnTimer = 0.0f;
        int pipe_y_offset_top = GetRandomValue(PIPE_H/2, GetScreenWidth()/2);
        PipePair pipePair;
        pipePair.top.x = GetScreenWidth();
        pipePair.bot.x = GetScreenWidth();
        pipePair.top.y = -pipe_y_offset_top;
        pipePair.bot.y = (PIPE_H - pipe_y_offset_top) + GetRandomValue(PIPE_H/2, GetScreenWidth()/2);
        pipePair.scored = false;
        pipes.push_back(pipePair);
    }
    
    for (int i = 0; i < pipes.size(); ++i)
    {
        pipes[i].top.x -= PIPE_SPEED * deltaTime;
        pipes[i].bot.x -= PIPE_SPEED * deltaTime;
        /*
        if(pipes[i].top.x + 64 <= 200) {
            pipes[i].scored = true;
            DrawText("SCORED!", 110, 224, 21, black);
        }*/
        if(pipes.front().top.x < 0 - PIPE_W) {
            pipes.pop_front();
        }
    }
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

        for (int i = 0; i < pipes.size(); ++i)
        {
            DrawRectangle(pipes[i].top.x, pipes[i].top.y, PIPE_W, PIPE_H, GREEN);
            DrawRectangle(pipes[i].bot.x, pipes[i].bot.y, PIPE_W, PIPE_H, GREEN);
        }
    }
    EndDrawing();  
}