#include <iostream>
#include <unordered_map>
#include <list>

class LRUCache {
    size_t capacity;
    std::list<int> order;
    std::unordered_map<int, std::list<int>::iterator> cache;

public:
    LRUCache(size_t cap) : capacity(cap) {}

    void put(int key) {
        if (cache.count(key)) {
            order.erase(cache[key]);
        } else if (order.size() == capacity) {
            int last = order.back();
            order.pop_back();
            cache.erase(last);
        }

        order.push_front(key);
        cache[key] = order.begin();
    }

    void print() {
        for (int x : order)
            std::cout << x << " ";
        std::cout << std::endl;
    }
};

int main() {
    LRUCache lru(3);

    lru.put(1);
    lru.put(2);
    lru.put(3);
    lru.print();

    lru.put(4);
    lru.print();
}
