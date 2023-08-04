//
// Created by Rokas on 8/3/2023.
//

#ifndef SMTH_TQUEUE_HPP
#define SMTH_TQUEUE_HPP

#include <queue>
#include <mutex>
#include <optional>

/**
 * TaskQueue
 *
 * An implementation of a thread-safe queue for (and not limited to) tasks
 * @tparam T: Object type to store in the queue
 */
template <typename T>
class TQueue {

private:
    std::queue<T> queue;
    mutable std::mutex mutex;

public:
    TQueue() = default;
    TQueue(const TQueue<T> &) = delete;
    TQueue& operator = (const TQueue<T> &) = delete;

    TQueue(TQueue<T> && other);
    virtual ~TQueue();

    unsigned long size() const;
    bool empty() const;

    std::optional<T> pop();
    void push(const T &item);
};


#endif //SMTH_TQUEUE_HPP
