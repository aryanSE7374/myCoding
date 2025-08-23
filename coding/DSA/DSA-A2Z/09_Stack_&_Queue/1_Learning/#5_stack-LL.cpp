#include <bits/stdc++.h>
using namespace std;

// Implement stack using linked list

class StackNode {
public:
    int data;
    StackNode* next;
    StackNode(int d) {
        data = d;
        next = NULL;
    }
};

class MyStack {
private:
    StackNode* top;
    int size;

public:
    MyStack() {
        top = NULL;
        size = 0;
    }

    void stackPush(int x) {
        StackNode* element = new StackNode(x);
        element->next = top;
        top = element;
        cout << "Element pushed" << "\n";
        size++;
    }

    int stackPop() {
        if (top == NULL) {
            return -1;
        }
        int topData = top->data;
        StackNode* temp = top;
        top = top->next;
        delete temp;
        size--;
        return topData;
    }

    int stackSize() {
        return size;
    }

    bool stackIsEmpty() {
        return top == NULL;
    }

    int stackPeek() {
        if (top == NULL) return -1;
        return top->data;
    }

    void printStack() {
        StackNode* current = top;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << "\n";
    }
};

int main() {
    MyStack s;
    s.stackPush(10);
    cout << "Element popped: " << s.stackPop() << "\n";
    cout << "Stack size: " << s.stackSize() << "\n";
    cout << "Stack empty or not? " << s.stackIsEmpty() << "\n";
    cout << "Stack's top element: " << s.stackPeek() << "\n";
    return 0;
}