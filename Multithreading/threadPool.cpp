#include <condition_variable>
#include <functional>
#include <vector>
#include <thread>
#include <queue>
#include <iostream>

class MemoryPool {
public:
    using Task = std::function<void()>;

    explicit MemoryPool(std::size_t numThreads) {
        start(numThreads);
    }

    ~MemoryPool() {
        stop();
    }

    void enque(Task task) {
        {
            std::unique_lock<std::mutex> lock{ m_mutex };
            m_queue.emplace(task);
        }
        m_eventVar.notify_one();
    }

private:

    std::vector<std::thread> m_threads;
    std::condition_variable m_eventVar;
    std::mutex m_mutex;
    std::queue<Task> m_queue;
    bool stopFlag = false;

    void start(std::size_t numThreads) {
        for (auto k = 0; k < numThreads; ++k) {
            m_threads.emplace_back([=] {
                while (true) {
                    Task task;
                    {
                        std::unique_lock<std::mutex> lock{ m_mutex };
                        m_eventVar.wait(lock, [=] {
                            return stopFlag || !m_queue.empty();
                        });

                        if (stopFlag && m_queue.empty())
                            break;

                        task = m_queue.front();
                        m_queue.pop();
                    }
                    task();
                }
            });
        }
    }

    void stop() {
        {
            std::unique_lock<std::mutex> lock{ m_mutex };
            stopFlag = true;
        }
        m_eventVar.notify_all();

        for (auto& thread : m_threads) {
            thread.join();
        }
    }

};

int main() {
    MemoryPool pool{ 4 };
    pool.enque([] {
        std::cout << "1" << "\n";
    });

    pool.enque([] {
        std::cout << "2" << "\n";
    });

    return 0;
}