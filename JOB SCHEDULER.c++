#include <iostream>
#include <queue>
#include <functional>
#include <chrono>
#include <thread>

using Clock = std::chrono::steady_clock;

struct Job {
    Clock::time_point time;
    std::function<void()> task;
    bool operator>(const Job& other) const {
        return time > other.time;
    }
};

int main() {
    std::priority_queue<Job, std::vector<Job>, std::greater<>> q;

    q.push({Clock::now() + std::chrono::seconds(1), [] {
        std::cout << "Job executed\n";
    }});

    while (!q.empty()) {
        if (Clock::now() >= q.top().time) {
            q.top().task();
            q.pop();
        }
    }
}
