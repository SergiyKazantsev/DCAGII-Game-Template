#pragma once
#include "GameState.hpp"
struct Bird {
    int x;
    int y;
    double vy;
    bool skip;
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
};