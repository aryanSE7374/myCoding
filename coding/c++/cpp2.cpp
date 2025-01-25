#include<iostream>
using namespace std;
struct node{
    int data;
    node *next;
    
    node(int val){
        data=val;
        next=NULL;
    }
};
void inserting_node(node *&head,int val){
    node *n= new node(val);
    node *temp=head;
    if(head==NULL){
        head=n;
        return;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}
void display(node *head){
    node *temp=head;
    
    while (temp->next!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<"NULL"<<endl;
}


int main() {
    node *head=NULL;
    inserting_node(head,1);
    inserting_node(head,2);
    inserting_node(head,3);
    inserting_node(head,4);
    display(head);
    return 0;
}