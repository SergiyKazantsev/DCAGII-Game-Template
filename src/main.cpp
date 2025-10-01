#include "StateMachine.hpp"
#include "MainMenuState.hpp"
#include "GamingState.hpp"
#include "GameOverState.hpp"
#include <memory>
#include <chrono>


int main()
{
    //Implement the main loop with delta time
    std::chrono::steady_clock::time_point last_time = std::chrono::steady_clock::now();
    std::chrono::steady_clock::time_point current_time;
    float delta_time = 0.0f;
    StateMachine state_machine = StateMachine();
    state_machine.add_state(std::make_unique<MainMenuState>(), false);
    state_machine.handle_state_changes(delta_time);

    InitWindow(288, 512, "Flappy Bird DCA");
    InitAudioDevice();
    SetTargetFPS(60);
    while (!state_machine.is_game_ending() && WindowShouldClose() == false)
    {
        if (state_machine.getCurrentState()->shouldSwitchState == true) {
            GameState* current = state_machine.getCurrentState().get();
            if (dynamic_cast<GamingState*>(current)) {
                auto gameover = std::make_unique<GameOverState>();
                gameover->score = current->score;
                state_machine.add_state(std::move(gameover), true);
            } else {
                state_machine.add_state(std::make_unique<GamingState>(), true);
            }
        }
        delta_time = GetFrameTime();
        state_machine.handle_state_changes(delta_time);
        state_machine.getCurrentState()->update(delta_time);
        state_machine.getCurrentState()->render();     
    }

    return 0;
}