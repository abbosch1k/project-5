#include <queue>
#include <mutex>

template<typename T>
class SafeQueue {
    std::queue<T> q;
    std::mutex m;
public:
    void push(T v) {
        std::lock_guard<std::mutex> l(m);
        q.push(v);
    }
    bool pop(T& out) {
        std::lock_guard<std::mutex> l(m);
        if (q.empty()) return false;
        out = q.front();
        q.pop();
        return true;
    }
};
