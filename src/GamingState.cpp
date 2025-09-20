#include "GamingState.hpp"
#include <iostream>

Color green = {173, 204, 96, 255};
Color black = {0, 0, 0, 255};

GamingState::GamingState()
{
}

void GamingState::init()
{
    std::cout << "You are in the Gaming State" << std::endl;
    player.x = 200;
    player.y = 200;
}

void GamingState::handleInput()
{
    if (IsKeyPressed(KEY_SPACE)) {
        player.vy = -300.0f;
        std::cout << "You entered ESPACIO "; 
    }
}

void GamingState::update(float deltaTime)
{ 
    this->handleInput();
    player.vy += 686.0f * deltaTime;
    player.y += player.vy * deltaTime;
    //std::cout << "player X:" << player.x << ", player Y: " << player.y << ", player VY: " << player.vy << "Delta time: "<< deltaTime << "\n";
    
    player.hitbox.x = player.x-17;
    player.hitbox.y = player.y-17;
    player.hitbox.height = 17*2;
    player.hitbox.width = 17*2;
    Vector2 origin;
    origin.x = player.hitbox.width / 2;
    origin.y = player.hitbox.height / 2;

    DrawRectangleRec(player.hitbox, black);

    spawnTimer += deltaTime;
    if(spawnTimer >= spawnEvery) {
        spawnTimer = 0.0f;
        int pipe_y_offset_top = GetRandomValue(PIPE_H/1.5, GetScreenWidth()/3);
        PipePair pipePair;
        pipePair.top.x = GetScreenWidth();
        pipePair.bot.x = GetScreenWidth();
        pipePair.top.y = -pipe_y_offset_top;
        pipePair.bot.y = (PIPE_H - pipe_y_offset_top) + GetRandomValue(PIPE_H/2, GetScreenWidth()/2);
        pipePair.scored = false;

        pipePair.top.height = PIPE_H;
        pipePair.top.width = PIPE_W;
        pipePair.bot.height = PIPE_H;
        pipePair.bot.width = PIPE_W;

        pipes.push_back(pipePair);
    }
    
    for (int i = 0; i < pipes.size(); ++i)
    {
        pipes[i].top.x -= PIPE_SPEED * deltaTime;
        pipes[i].bot.x -= PIPE_SPEED * deltaTime;
        if(CheckCollisionRecs(pipes[i].top, player.hitbox) || CheckCollisionRecs(pipes[i].bot, player.hitbox)) {
            DrawText("COLISION!", 110, 224, 21, RED);
        }
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

void GamingState::render()
{
    BeginDrawing();
    ClearBackground(green);
    DrawCircle(player.x, player.y, 17, RED);

    for (int i = 0; i < pipes.size(); ++i)
    {
        DrawRectangleRec(pipes[i].top, GREEN);
        DrawRectangleRec(pipes[i].bot, GREEN);
    }
    EndDrawing();  
}