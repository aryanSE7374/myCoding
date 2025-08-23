#include<bits/stdc++.h>
using namespace std;

// striver's solution 1 (youtube video pseudo code)

class LRUCache {
public:
    // Node class for DLL
    class Node {
    public:
        int key;
        int val;
        Node * next;
        Node * prev;
        Node(int _key, int _val) {
            key = _key;
            val = _val;
        }
    };

    // public data fields
    Node * head = new Node(-1, -1);
    Node * tail = new Node(-1, -1);
    int cap;
    unordered_map < int, Node * > mapp;

    // constructor
    LRUCache(int capacity) {
        cap = capacity;
        head -> next = tail;
        tail -> prev = head;
    }

    void insertAfterHead(Node * newnode) {
        Node * temp = head -> next;
        newnode -> next = temp;
        newnode -> prev = head;
        head -> next = newnode;
        temp -> prev = newnode;
    }

    void deleteNode(Node * delnode) {
        Node * delprev = delnode -> prev;
        Node * delnext = delnode -> next;
        delprev -> next = delnext;
        delnext -> prev = delprev;
    }

    int get(int key_) {
        if (mapp.find(key_) != mapp.end()) {
            Node * resNode = mapp[key_];
            deleteNode(resNode);
            insertAfterHead(resNode);
            mapp[key_] = head->next; // 🔧 FIX: update the map
            return resNode->val;
        }

        return -1;
    }

    void put(int key_, int value) {
        if (mapp.find(key_) != mapp.end()) { // if key exists in mapp then update the value
            Node * existingnode = mapp[key_];
            existingnode->val = value;
            deleteNode(existingnode);
            insertAfterHead(existingnode);
        }
        else{
            if (mapp.size() == cap) {
                Node* newNode = tail->prev;
                mapp.erase(newNode -> key);
                deleteNode(newNode);
            }
            Node* node = new Node(key_, value);
            insertAfterHead(node);
            mapp[key_] = node;
        }
    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// ------------------------------------------------------------------------------------------------------------------------------------ // 

 // striver's solution 2 (website code)

 class LRUCache {
  public:
    class node {
      public:
        int key;
        int val;
        node * next;
        node * prev;
        node(int _key, int _val) {
            key = _key;
            val = _val;
        }
    };

  node * head = new node(-1, -1);
  node * tail = new node(-1, -1);

  int cap;
  unordered_map < int, node * > m;

  LRUCache(int capacity) {
    cap = capacity;
    head -> next = tail;
    tail -> prev = head;
  }

  void addnode(node * newnode) {
    node * temp = head -> next;
    newnode -> next = temp;
    newnode -> prev = head;
    head -> next = newnode;
    temp -> prev = newnode;
  }

  void deletenode(node * delnode) {
    node * delprev = delnode -> prev;
    node * delnext = delnode -> next;
    delprev -> next = delnext;
    delnext -> prev = delprev;
  }

  int get(int key_) {
    if (m.find(key_) != m.end()) {
      node * resnode = m[key_];
      int res = resnode -> val;
      m.erase(key_);
      deletenode(resnode);
      addnode(resnode);
      m[key_] = head -> next;
      return res;
    }

    return -1;
  }

  void put(int key_, int value) {
    if (m.find(key_) != m.end()) {
      node * existingnode = m[key_];
      m.erase(key_);
      deletenode(existingnode);
    }
    if (m.size() == cap) {
      m.erase(tail -> prev -> key);
      deletenode(tail -> prev);
    }

    addnode(new node(key_, value));
    m[key_] = head -> next;
  }
};

// ------------------------------------------------------------------------------------------------------------------------------------ // 