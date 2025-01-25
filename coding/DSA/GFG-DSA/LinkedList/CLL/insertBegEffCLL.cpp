#include <bits/stdc++.h> 
using namespace std; 

struct Node{
    int data;
    Node* next;
    Node(int d){
        data=d;
        next=NULL;
    }
};

void printlist(Node *head){
    if(head==NULL)return;
    Node *p=head;
    do{
        cout<<p->data<<" ";
        p=p->next;
    }while(p!=head);
}

// O(1) 
// insert the temp node just after the head and then swap the data of temp and head

Node *insertBegin(Node * head,int x){
    Node *temp=new Node(x);
    if(head==NULL){ //corner case for empty list
        temp->next=temp; //self-loop
        return temp;    
    }
    else{
        // insert temp after head
        temp->next=head->next;
        head->next=temp;
        //swap data of temp and head
        int t=head->data;
        head->data=temp->data;
        temp->data=t;
        //return
        return head;
    }
}

int main() 
{ 
	Node *head=new Node(10);
	head->next=new Node(20);
	head->next->next=new Node(30);
	head->next->next->next=head;
	head=insertBegin(head,15);
	printlist(head);
	return 0;
} 
