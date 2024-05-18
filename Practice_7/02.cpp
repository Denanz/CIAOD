#include <iostream>
#include <stdexcept>

struct Node {
    int value;
    Node* next;
    Node(int v) : value(v), next(nullptr) {}
};

class Queue {
public:
    Queue() : front(nullptr), rear(nullptr) {}

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (rear) {
            rear->next = newNode;
        }
        rear = newNode;
        if (!front) {
            front = newNode;
        }
    }

    int dequeue() {
        if (isEmpty()) {
            throw std::runtime_error("dequeue from empty queue");
        }
        int value = front->value;
        Node* oldFront = front;
        front = front->next;
        delete oldFront;
        if (!front) {
            rear = nullptr;
        }
        return value;
    }

    bool isEmpty() const {
        return front == nullptr;
    }

    void printQueue() const {
        Node* current = front;
        while (current) {
            std::cout << current->value << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

private:
    Node* front;
    Node* rear;
};

int main() {
    Queue queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.printQueue();  // 1 2 3
    std::cout << queue.dequeue() << std::endl;  // 1
    queue.printQueue();  // 2 3
    std::cout << std::boolalpha << queue.isEmpty() << std::endl;  // false
    queue.dequeue();
    queue.dequeue();
    std::cout << std::boolalpha << queue.isEmpty() << std::endl;  // true
    return 0;
}
