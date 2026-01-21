#include <iostream>
#include <vector>
#include <functional>

class EventBus {
    std::vector<std::function<void(int)>> subs;
public:
    void subscribe(auto cb) { subs.push_back(cb); }
    void emit(int data) {
        for (auto& cb : subs) cb(data);
    }
};

int main() {
    EventBus bus;
    bus.subscribe([](int x){ std::cout << "A got " << x << "\n"; });
    bus.subscribe([](int x){ std::cout << "B got " << x << "\n"; });

    bus.emit(42);
}
