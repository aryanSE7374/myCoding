#include<bits/stdc++.h>
using namespace std;

// leetcode struct definition of SLL : 

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// The part after the colon (:) is called an initializer list.
/*
// The same constructor could also be written without an initializer list like this:
ListNode(int x) {
    val = x;
    next = NULL;
}
*/

// SLL creation 

class Node{
public: // access modifier
    int data; // the data value
    Node* next; // the pointer to the next value
    // Public:
    // constructor
public:
    Node (int data1, Node* next1){
        data=data1;  // Initialize data with the provided value
        next=next1;  // Initialize next with the provided
    }
    Node (int data1){
        data=data1;  // Initialize data with the provided value
        next=nullptr;  // Initialize next as null since it's the end of the list

    }
};
int main(){


    // understanding pointers : 
    int x=2;
    int* y2=&x; // y reference x
    cout<<y2<<'\n';

    vector<int> arr={2,5,8,7};
    Node* y= new Node(arr[0]);
    cout<<"memory value : "<<y<<'\n'; // returns the memory value
    cout<<"data sores : "<<y->data<<'\n'; // returns the data stored at that memory point
}


/*
// memiry : 
32 Bit System	    ||   64 Bit System
Int - 4 Bytes	    ||   Int - 4 Bytes
Pointer - 4 Bytes	||   Pointer - 8 Bytes
Overall - 8 Bytes	||   Overall - 12 Bytes
*/