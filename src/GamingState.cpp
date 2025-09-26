#include "GamingState.hpp"
#include <iostream>

Color green = {173, 204, 96, 255};
Color black = {0, 0, 0, 255};

GamingState::GamingState()
{
    this->score = 0;
}

void GamingState::init()
{
    std::cout << "You are in the Gaming State" << std::endl;
    player.x = 200;
    player.y = 200;
    player.height = 24;
    player.width = 34;
    this->shouldSwitchState = false;

    this->birdSprite = LoadTexture("./assets/yellowbird-upflap.png");   
    this->pipeeSprite = LoadTexture("./assets/pipe-green.png");
    this->background = LoadTexture("./assets/background-day.png");
}

void GamingState::handleInput()
{
    if (IsKeyPressed(KEY_SPACE)) {
        player.vy = -300.0f;
        //std::cout << "You entered ESPACIO "; 
    }
}

void GamingState::update(float deltaTime)
{ 
    this->handleInput();
    player.vy += 686.0f * deltaTime;
    player.y += player.vy * deltaTime;
    //std::cout << "player X:" << player.x << ", player Y: " << player.y << ", player VY: " << player.vy << "Delta time: "<< deltaTime << "\n";
    
    player.hitbox.x = player.x;
    player.hitbox.y = player.y;
    player.hitbox.height = player.height;
    player.hitbox.width = player.width;

    //DrawRectangleRec(player.hitbox, black);

    spawnTimer += deltaTime;
    if(spawnTimer >= spawnEvery) {
        spawnTimer = 0.0f;
        int pipe_y_offset_top = GetRandomValue(PIPE_H/2, GetScreenWidth()/2);
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
        if(CheckCollisionRecs(pipes[i].top, player.hitbox) || CheckCollisionRecs(pipes[i].bot, player.hitbox) || player.y > GetScreenHeight() || player.y < -100) {
            this->shouldSwitchState = true;
            return;
        }
        if(pipes[i].top.x + PIPE_W <= player.x && pipes[i].scored == false) {
            std::cout << "Scoring! Pipe x: " << pipes[i].top.x << ", Player x: " << player.x << std::endl;
            pipes[i].scored = true;
            this->score++;
        }
        if(pipes.front().top.x < 0 - PIPE_W) {
            pipes.pop_front();
        }
    }
}

void GamingState::render()
{
    BeginDrawing();
    ClearBackground(green);
    DrawTexture(background, 0, 0, WHITE);
    DrawTexture(this->birdSprite, player.x, player.y, WHITE);
    for (int i = 0; i < pipes.size(); ++i)
    {
        DrawTextureEx(this->pipeeSprite, {pipes[i].top.x + PIPE_W, pipes[i].top.y + PIPE_H}, 180.f, 1.0f, WHITE);
        DrawTextureEx(this->pipeeSprite, {pipes[i].bot.x , pipes[i].bot.y}, 0.f, 1.0f, WHITE); 
    }
    std::string text = "Puntuación: " + std::to_string(score);
    DrawText(text.c_str(), 20, 20, 30, DARKBLUE);
    EndDrawing();  
}