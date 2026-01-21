#include <iostream>

enum class State { IDLE, RUNNING, STOPPED };

int main() {
    State s = State::IDLE;

    s = State::RUNNING;
    if (s == State::RUNNING)
        std::cout << "Working...\n";

    s = State::STOPPED;
}
