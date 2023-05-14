#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {
private:
    T data;
    Node<T>* next;
    Node<T>* previous;

public:
    Node(T data = T(), Node<T>* next = nullptr, Node<T>* previous = nullptr)
        : data(data), next(next), previous(previous) {}

    T getData() const {
        return data;
    }

    void setData(T newData) {
        data = newData;
    }

    Node<T>* getNext() const {
        return next;
    }

    void setNext(Node<T>* nextNode) {
        next = nextNode;
    }

    Node<T>* getPrevious() const {
        return previous;
    }

    void setPrevious(Node<T>* previousNode) {
        previous = previousNode;
    }
};

#endif // NODE_H
