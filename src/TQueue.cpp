//
// Created by Rokas on 8/3/2023.
//

#include "TQueue.hpp"

template<typename T>
bool TQueue<T>::empty() const {
    return queue.empty();
}

template<typename T>
void TQueue<T>::push(const T &item) {
    std::lock_guard<std::mutex> lock(mutex);
    queue.push(item);
}

template<typename T>
std::optional<T> TQueue<T>::pop() {
    std::lock_guard<std::mutex> lock(mutex);
    if (queue.empty()) {
        return {};
    }
    T tmp = queue.front();
    queue.pop();
    return tmp;
}

template<typename T>
unsigned long TQueue<T>::size() const {
    std::lock_guard<std::mutex> lock(mutex);
    return queue.size();
}

template<typename T>
TQueue<T>::~TQueue() {}

template<typename T>
TQueue<T>::TQueue(TQueue<T> &&other) {
    std::lock_guard<std::mutex> lock(mutex);
    queue = std::move(other.queue);
}
