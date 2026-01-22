#include <iostream>
#include <vector>
#include <queue>
#include <thread>
#include <future>
#include <mutex>
#include <condition_variable>

class ThreadPool {
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;

    std::mutex m;
    std::condition_variable cv;
    bool stop = false;

public:
    ThreadPool(size_t n) {
        for (size_t i = 0; i < n; ++i)
            workers.emplace_back([this] {
                while (true) {
                    std::function<void()> task;
                    {
                        std::unique_lock<std::mutex> lock(m);
                        cv.wait(lock, [&] { return stop || !tasks.empty(); });
                        if (stop && tasks.empty()) return;
                        task = std::move(tasks.front());
                        tasks.pop();
                    }
                    task();
                }
            });
    }

    template<class F>
    auto submit(F f) -> std::future<decltype(f())> {
        using R = decltype(f());
        auto task = std::make_shared<std::packaged_task<R()>>(f);
        auto res = task->get_future();

        {
            std::lock_guard<std::mutex> lock(m);
            tasks.emplace([task]{ (*task)(); });
        }
        cv.notify_one();
        return res;
    }

    ~ThreadPool() {
        {
            std::lock_guard<std::mutex> lock(m);
            stop = true;
        }
        cv.notify_all();
        for (auto& w : workers) w.join();
    }
};
