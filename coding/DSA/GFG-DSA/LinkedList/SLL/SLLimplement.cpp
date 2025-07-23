#include <bits/stdc++.h> 
using namespace std; 

struct Node{
    int data;
    Node* next;
    Node(int x){
        data=x;
        next=NULL;
    }
};

int main() 
{ 
	Node *head=new Node(10);
	Node *temp1=new Node(20);
	Node *temp2=new Node(30);
	head->next=temp1;
	temp1->next=temp2;
	cout<<head->data<<"-->"<<temp1->data<<"-->"<<temp2->data;
	return 0;
} 

//Applications of LinkedList : 
/*
1. Worst Case Insertions(at End and Beginning) take O(1) time.
2. Worst Case deletions(from the Beginning) take O(1) time.
3. Insertions and Deletions in the middle are Theta(1) if we have reference to the previous node.
4. Round Robin Implementation
5. Merging two sorted Linked Lists is faster than Arrays
6. Implementation of simple memory manager where is need to link free blocks is easier
7. Easy implementation of Queue and Dequeue Data Structures.
*/
