#pragma once
#include "GameState.hpp"
#include <deque>

struct Bird {
    int x;
    int y;
    double vy;
    bool skip;
};

struct PipePair {
    Rectangle top;
    Rectangle bot;
    bool scored = false; // si el jugador pasó por los tubos
};


class MainMenuState : public GameState
{
    public:
        MainMenuState();
        ~MainMenuState() = default;

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