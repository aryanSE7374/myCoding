#include <iostream>
#include <vector>
#include <queue>

// Abstract Base Class
class LIST {
public:
    virtual void store(int value) = 0;
    virtual int retrieve() = 0;
    virtual ~LIST() {}
};

// Derived Class: stack
class stack : public LIST {
private:
    std::vector<int> elements;
public:
    void store(int value) override {
        elements.push_back(value);
    }
    int retrieve() override {
        if (!elements.empty()) {
            int value = elements.back();
            elements.pop_back();
            return value;
        }
        throw std::runtime_error("Stack is empty");
    }
};

// Derived Class: queue
class queue : public LIST {
private:
    std::queue<int> elements;
public:
    void store(int value) override {
        elements.push(value);
    }
    int retrieve() override {
        if (!elements.empty()) {
            int value = elements.front();
            elements.pop();
            return value;
        }
        throw std::runtime_error("Queue is empty");
    }
};

int main() {
    LIST* myStack = new stack();
    LIST* myQueue = new queue();

    myStack->store(10);
    myStack->store(20);
    std::cout << "Stack retrieve: " << myStack->retrieve() << std::endl; // 20

    myQueue->store(30);
    myQueue->store(40);
    std::cout << "Queue retrieve: " << myQueue->retrieve() << std::endl; // 30

    delete myStack;
    delete myQueue;

    return 0;
}
