#ifndef SDP_DEQUE_H
#define SDP_DEQUE_H

#include <stdexcept>

template <typename T>
struct Node {
    T data;
    Node<T>* next;
    Node<T>* prev;
};

template <typename T>
class Deque {
public:
    Deque();
    Deque(const Deque<T>&);
    Deque<T>& operator=(const Deque<T>&);
    ~Deque();

    //move semantics
    Deque(Deque<T>&&) noexcept;
    Deque<T>& operator=(Deque<T>&&) noexcept;

    [[nodiscard]]
    bool empty() const;
    void push_front(const T&);
    void push_back(const T&);
    void pop_front();
    void pop_back();
    T& head();
    T& tail();
    const T& head() const;
    const T& tail() const;

private:
    Node<T> *front, *back;

    void copy_deque(const Deque<T>&);
    void erase();

};

template<typename T>
void Deque<T>::erase() {
    while (!empty()) {
        pop_back();
    }
}

template<typename T>
void Deque<T>::copy_deque(const Deque<T>& other) {
    if (other.empty()) {
        front = back = nullptr;
    }

    Node<T>* node_ptr = other.front;
    while (node_ptr) {
        push(node_ptr->data);
        node_ptr = node_ptr->next;
    }
}

template<typename T>
const T& Deque<T>::tail() const {
    if (empty()) {
        throw std::runtime_error("The deque is empty!");
    }

    return back->data;
}

template<typename T>
const T& Deque<T>::head() const {
    if (empty()) {
        throw std::runtime_error("The deque is empty!");
    }

    return front->data;
}

template<typename T>
T& Deque<T>::head() {
    if (empty()) {
        throw std::runtime_error("The deque is empty!");
    }

    return front->data;
}

template<typename T>
T& Deque<T>::tail() {
    if (empty()) {
        throw std::runtime_error("The queue is empty!");
    }

    return back->data;
}

template<typename T>
bool Deque<T>::empty() const {
    return (front == nullptr && back == nullptr);
}

template<typename T>
void Deque<T>::push_front(const T& element) {
    auto node_ptr = new Node<T>{element, nullptr, front};

    if (!empty()) {
        front->prev = node_ptr;
    }
    else {
        back = node_ptr;
    }

    front = node_ptr;
}

template<typename T>
void Deque<T>::push_back(const T& element) {
    auto node_ptr = new Node<T>{element, back, nullptr};

    if (!empty()) {
        back->next = node_ptr;
    }
    else {
        front = node_ptr;
    }

    back = node_ptr;
}

template<typename T>
void Deque<T>::pop_back() {
    if (empty()) {
        throw std::runtime_error("Can not delete element from an empty deque");
    }

    Node<T>* node_ptr = front;

    front = front->next;

    if (front == nullptr) {
        back = nullptr;
    }

    delete node_ptr;
}

template<typename T>
void Deque<T>::pop_front() {
    if (empty()) {
        throw::std::runtime_error("Can not delete element from an empty deque");
    }

    Node<T>* node_ptr = back;

    back = back->prev;

    if (back == nullptr) {
        front = nullptr;
    }

    delete node_ptr;
}


//
template<typename T>
Deque<T>::Deque() : front(nullptr), back(nullptr) {}

template<typename T>
Deque<T>::Deque(const Deque<T>& other) {
    copy_deque(other);
}

template<typename T>
Deque<T>& Deque<T>::operator=(const Deque<T>& other) {
    if (&other != this) {
        erase();
        copy_deque(other);
    }

    return *this;
}

template<typename T>
Deque<T>::~Deque() {
    erase();
}

//move semantics
template<typename T>
Deque<T>::Deque(Deque<T>&& other) noexcept {
    front = other.front;
    back = other.back;
    other.front = nullptr;
    other.back = nullptr;
}

template<typename T>
Deque<T>& Deque<T>::operator=(Deque<T> && other) noexcept {
    if (this != &other) {
        erase();

        front = other.front;
        back = other.back;
        other.front = nullptr;
        other.back = nullptr;
    }
}


#endif //SDP_DEQUE_H
