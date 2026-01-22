#include <list>
#include <unordered_map>
#include <mutex>

class LRUCache {
    size_t cap;
    std::list<int> order;
    std::unordered_map<int, std::list<int>::iterator> map;
    std::mutex m;

public:
    LRUCache(size_t c): cap(c) {}

    void put(int k) {
        std::lock_guard<std::mutex> lock(m);
        if (map.count(k)) order.erase(map[k]);
        else if (order.size() == cap) {
            map.erase(order.back());
            order.pop_back();
        }
        order.push_front(k);
        map[k] = order.begin();
    }
};
