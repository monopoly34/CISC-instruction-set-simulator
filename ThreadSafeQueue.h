#ifndef CISC_INSTRUCTION_SET_SIMULATOR_THREADSAFEQUEUE_H
#define CISC_INSTRUCTION_SET_SIMULATOR_THREADSAFEQUEUE_H

#include <queue>
#include <mutex>
#include <condition_variable>

using namespace std;

template <typename T>
class ThreadSafeQueue {
    queue<T> queue;
    mutex mtx;
    condition_variable cv;

public:
    // adauga un element in coada de mesaje si trezeste threaad ul care asteapta
    void push(T value) {
        lock_guard<mutex> lock(mtx);
        queue.push(value);
        cv.notify_one();
    }

    // scoate un element (daca coada este goala, blocheaza firul de executie pana apare un element)
    T pop() {
        unique_lock<mutex> lock(mtx);

        // wait face ca firul curent sa se blocheze pana conditia variabila este notifica prin notify_one()
        cv.wait(lock, [this] { return !queue.empty(); });

        T value = queue.front();
        queue.pop();

        return value;
    }
};

#endif //CISC_INSTRUCTION_SET_SIMULATOR_THREADSAFEQUEUE_H
