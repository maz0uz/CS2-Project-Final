#ifndef DEQ_H
#define DEQ_H
#include <stdexcept>
#include "Node.h"
template <typename T>
class DEQ {
private:
    Node<T>* front;
    Node<T>* rear;
    int length;

public:
    DEQ() : front(nullptr), rear(nullptr), length(0) {}

    ~DEQ() {
        while (front != nullptr) {
            Node<T>* temp = front;
            front = front->getNext();
            delete temp;
        }
    }

    bool DEQisEmpty() const {
        return length == 0;
    }

    void Add_Front(T data) {
        Node<T>* newNode = new Node<T>(data);

        if (DEQisEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            newNode->setNext(front);
            front->setPrevious(newNode);
            front = newNode;
        }

        length++;
    }

    void Add_Rear(T data) {
        Node<T>* newNode = new Node<T>(data);

        if (DEQisEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            newNode->setPrevious(rear);
            rear->setNext(newNode);
            rear = newNode;
        }

        length++;
    }

    T Remove_Front() {
        if (DEQisEmpty()) {
            throw std::runtime_error("Error: empty deque. Cannot remove front element.");
        }

        Node<T>* temp = front;
        T data = temp->getData();

        if (front == rear) {
            front = nullptr;
            rear = nullptr;
        } else {
            front = front->getNext();
            front->setPrevious(nullptr);
        }

        delete temp;
        length--;

        return data;
    }

    T Remove_Rear() {
        if (DEQisEmpty()) {
            throw std::runtime_error("Error: empty deque. Cannot remove rear element.");
        }

        Node<T>* temp = rear;
        T data = temp->getData();

        if (front == rear) {
            front = nullptr;
            rear = nullptr;
        } else {
            rear = rear->getPrevious();
            rear->setNext(nullptr);
        }

        delete temp;
        length--;

        return data;
    }

    T View_Front() const {
        if (DEQisEmpty()) {
            throw std::runtime_error("Error: empty deque. Cannot view front element.");
        }

        return front->getData();
    }

    T View_Rear() const {
        if (DEQisEmpty()) {
            throw std::runtime_error("Error: empty deque. Cannot view rear element.");
        }

        return rear->getData();
    }

    int DEQ_Length() const {
        return length;
    }
};

#endif // DEQ_H
