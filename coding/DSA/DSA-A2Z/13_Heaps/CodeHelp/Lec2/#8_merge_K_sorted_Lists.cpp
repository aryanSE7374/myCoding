#include<bits/stdc++.h>
using namespace std;

// Leetcode version (hard)
// https://leetcode.com/problems/merge-k-sorted-lists/description/

// Brute Solution
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        vector<int> vec;
        for(auto& list : lists ){
            ListNode* curr = list;
            while(curr!=NULL){
                vec.push_back(curr->val);
                curr = curr->next;
            }
        }

        sort(vec.begin() , vec.end());

        ListNode* dummy = new ListNode(-1); // dummy node
        ListNode* curr = dummy;

        for(int& num : vec){
            curr->next = new ListNode(num);
            curr = curr->next;
        }

        return dummy->next;

    }
};

// ------------------------------------------------------------ //

// optimal approach

class compare{
    public: 
        bool operator()(ListNode* a , ListNode* b){
            return a->val > b->val ;
        }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue< ListNode* , vector<ListNode*> , compare > minHeap;

        for(auto& list : lists ){
            if(list!=NULL){
                minHeap.push(list);
            }
        }
        
        ListNode* head = NULL;
        ListNode* tail = NULL;

        while(!minHeap.empty()){

            ListNode* top = minHeap.top();
            minHeap.pop();

            if(top->next != NULL){
                minHeap.push(top->next);
            }

            if(head == NULL){
                head = top;
                tail = top;
            }
            else{
                tail->next = top;
                tail = top;
            }

        }

        return head;

    }
};





// ------------------------------------------------------------ //

// code 360 version
// https://www.naukri.com/code360/problems/merge-k-sorted-lists_992772?leftPanelTabValue=PROBLEM


//approach 1

// vector<int> ans; -> sc=O(N*K)
// join all LL
// Replace LL nodes data with vector data
//TC = N*KLog(K) + (N*K) + (N*K)


// ------------------------------------------------------------ //


//approach 2 : optimal approach

// minheap -> fist element of k-LL
//ans LL -> head/tail -> head used to return and tail for insertion
//while(minHeap is not empty logic)
//SC => O(K)
//TC => O(KLogK) + O(N*KLogK) => O(N*KLogK) => O(NLogK)


#include<queue>

// Following is the class structure of the Node class:

class Node
{
    public:
        int data;
        Node *next;
        Node()
        {
            this->data = 0;
            next = NULL;
        }
        Node(int data)
        {
            this->data = data; 
            this->next = NULL;
        }
        Node(int data, Node* next)
        {
            this->data = data;
            this->next = next;
        }
};


class compare{
    public:
        bool operator()(Node* a, Node* b){
            return a->data > b->data;
        }
};

Node* mergeKLists(vector<Node*> &listArray)
{
    priority_queue<Node*, vector<Node*>, compare> minHeap;

    int k = listArray.size();
    if(k==0)
        return NULL;

    //step-1 : push the head of each list(if not NULL) to the minHeap
    for(int i=0; i<k; i++){
        if(listArray[i] != NULL){
            minHeap.push(listArray[i]);
        }
    }


    Node* head = NULL;
    Node* tail = NULL;

    //step-2
    while(!minHeap.empty()){

        Node* top = minHeap.top();
        minHeap.pop();

        if(top -> next != NULL)
        {
            minHeap.push(top -> next);
        }

        // if first node , then assign head
        if(head == NULL)
        {
            head = top;
            tail = top;
        }
        else
        {
            tail -> next = top;
            tail = top;
        }
    }
    return head;
}


// ------------------------------------------------------------ //

// GFG version

/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/


class compare{
    public:
        bool operator()(Node* a, Node* b){
            return a->data > b->data;
        }
};

class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        // code here
        priority_queue<Node*, vector<Node*>, compare> minHeap;

        int k = arr.size();
        if(k==0)
            return NULL;
    
        //step-1
        for(int i=0; i<k; i++){
            if(arr[i] != NULL){
                minHeap.push(arr[i]);
            }
        }
    
    
        Node* head = NULL;
        Node* tail = NULL;
    
        //step-2
        while(!minHeap.empty()){
    
            Node* top = minHeap.top();
            minHeap.pop();
    
            if(top -> next != NULL)
            {
                minHeap.push(top -> next);
            }
    
            if(head == NULL)
            {
                head = top;
                tail = top;
            }
            else
            {
                tail -> next = top;
                tail = top;
            }
        }
        return head;
    }
};