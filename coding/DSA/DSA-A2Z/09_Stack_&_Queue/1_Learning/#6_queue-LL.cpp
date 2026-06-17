#include <bits/stdc++.h>
using namespace std;

// Implement Queue using Linked List

class QueueNode {
public:
    int val;
    QueueNode* next;
    QueueNode(int data) {
        val = data;
        next = nullptr;
    }
};

class Queue {
private:
    QueueNode* Front;
    QueueNode* Rear;

public:
    int size; // NOTE : should be private

    Queue() {
        Front = nullptr;
        Rear = nullptr;
        size = 0;
    }

    bool Empty() {
        return Front == nullptr;
    }

    void Enqueue(int value) {
        QueueNode* Temp = new QueueNode(value);
        if (Temp == nullptr) {
            cout << "Queue is Full" << endl;
        } else {
            if (Front == nullptr) {
                Front = Temp;
                Rear = Temp;
            } else {
                Rear->next = Temp;
                Rear = Temp;
            }
            cout << value << " Inserted into Queue " << endl;
            size++;
        }
    }

    void Dequeue() {
        if (Front == nullptr) {
            cout << "Queue is Empty" << endl;
        } else {
            cout << Front->val << " Removed From Queue" << endl;
            QueueNode* Temp = Front;
            Front = Front->next;
            delete Temp;
            size--;
        }
    }

    int Peek() {
        if (Empty()) {
            cout << "Queue is Empty" << endl;
            return -1;
        } else {
            return Front->val;
        }
    }
};

int main() {
    Queue Q;
    Q.Enqueue(10);
    Q.Enqueue(20);
    Q.Enqueue(30);
    Q.Enqueue(40);
    Q.Enqueue(50);
    Q.Dequeue();
    cout << "The size of the Queue is " << Q.size << endl;
    cout << "The Peek element of the Queue is " << Q.Peek() << endl;
    return 0;
}