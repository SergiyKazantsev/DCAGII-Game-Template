#pragma once
#include "GameState.hpp"
#include <deque>

struct Bird {
    int x;
    int y;
    double vy;
    Rectangle hitbox;
};

struct PipePair {
    Rectangle top;
    Rectangle bot;
    bool scored = false; // si el jugador pasó por los tubos
};


class GamingState : public GameState
{
    public:
        GamingState();
        ~GamingState() = default;
        

        void init() override;
        void handleInput() override;
        void update(float deltaTime) override;
        void render() override;

        void pause(){};
        void resume(){};

    
    private:
        Bird player;
        char entered_key;
        std::deque<PipePair> pipes;
        int PIPE_W = 64;
        int PIPE_H = 320;
        float spawnTimer = 0.0f;
        float spawnEvery = 1.5f;
        int PIPE_SPACE = 32;
        float PIPE_SPEED = 200.0f;
};