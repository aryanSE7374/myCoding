#include <bits/stdc++.h>
using namespace std;

// THIS PROBLEM NEEDS A LOT MORE TIME 

// striver's implementation 1

/*
https://drive.google.com/file/d/1vVUwrQamg_Jy4-NodT63Hcu4YiwJksxd/view?usp=drive_link
https://docs.google.com/document/d/1dLJ6Dwlmipc_nxfoQD7qVWmpRA5QpVbU/edit?usp=drive_link&ouid=103765007342372907204&rtpof=true&sd=true
*/

struct Node {
    int key, value, cnt;
    Node *next;
    Node *prev;
    Node(int _key, int _value) {
        key = _key;
        value = _value;
        cnt = 1;
    }
};

struct List {
    int size;
    Node *head;
    Node *tail;
    List() {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addFront(Node *node) {
        Node *temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
        size++;
    }

    void removeNode(Node *delnode) {
        Node *delprev = delnode->prev;
        Node *delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
        size--;
    }
};

class LFUCache {
    map<int, Node*> keyNode;
    map<int, List*> freqListMap;
    int maxSizeCache;
    int minFreq;
    int curSize;

public:
    LFUCache(int capacity) {
        maxSizeCache = capacity;
        minFreq = 0;
        curSize = 0;
    }

    void updateFreqListMap(Node *node) {
        // keyNode.erase(node->key); // erasing and reinserting the node is not mandatory
        freqListMap[node->cnt]->removeNode(node); //removing node from freqListMap of the current count(freq of used)
        // check if current count is minFreq and and minFreqList has no elements => nimFreq has to be increased along with the count of this node
        if (node->cnt == minFreq && freqListMap[node->cnt]->size == 0) {
            minFreq++;
        }

        List *nextHigherFreqList = new List();
        if (freqListMap.find(node->cnt + 1) != freqListMap.end()) {
            nextHigherFreqList = freqListMap[node->cnt + 1];
        }

        node->cnt += 1;
        nextHigherFreqList->addFront(node);
        freqListMap[node->cnt] = nextHigherFreqList;
        // keyNode[node->key] = node; // erasing and reinserting the node is not mandatory
    }

    int get(int key) {
        if (keyNode.find(key) != keyNode.end()) {
            Node *node = keyNode[key];
            int val = node->value;
            updateFreqListMap(node);
            return val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (maxSizeCache == 0) {
            return;
        }

        if (keyNode.find(key) != keyNode.end()) {
            Node *node = keyNode[key];
            node->value = value;
            updateFreqListMap(node);
        } else {
            if (curSize == maxSizeCache) {
                List *list = freqListMap[minFreq];
                keyNode.erase(list->tail->prev->key);
                freqListMap[minFreq]->removeNode(list->tail->prev);
                curSize--;
            }

            curSize++;
            minFreq = 1;
            
            /*
            List *listFreq = new List();
            if (freqListMap.find(minFreq) != freqListMap.end()) {
                listFreq = freqListMap[minFreq];
            }
            */
            // better saves memory leak every time a newMinFreq list is not to be allocated
            List *listFreq;
            if (freqListMap.find(minFreq) != freqListMap.end()) {
                listFreq = freqListMap[minFreq];
            } else {
                listFreq = new List();
            }

            Node *node = new Node(key, value);
            listFreq->addFront(node);
            keyNode[key] = node;
            freqListMap[minFreq] = listFreq;
        }
    }
};


// ------------------------------------------------------------------------------------------------------------------------------------ // 
// ------------------------------------------------------------------------------------------------------------------------------------ // 


// chat GPT comments 

#include <bits/stdc++.h>
using namespace std;

// Node structure to store key, value, frequency, and pointers for DLL
struct Node {
    int key, value, cnt;     // cnt = frequency count
    Node *next, *prev;       // pointers for doubly linked list (DLL)

    Node(int _key, int _value) {
        key = _key;
        value = _value;
        cnt = 1;              // initialize frequency to 1
    }
};

// Doubly Linked List structure to maintain order of nodes of same frequency
struct List {
    int size;                 // number of nodes in the list
    Node *head;               // dummy head
    Node *tail;               // dummy tail

    List() {
        head = new Node(0, 0);    // dummy head node
        tail = new Node(0, 0);    // dummy tail node
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    // Add node right after head (most recently used position)
    void addFront(Node *node) {
        Node *temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
        size++;
    }

    // Remove a node from its current position in the list
    void removeNode(Node *delnode) {
        Node *delprev = delnode->prev;
        Node *delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
        size--;
    }
};

// LFU Cache class
class LFUCache {
    map<int, Node*> keyNode;        // Maps key to its node (O(1) lookup)
    map<int, List*> freqListMap;    // Maps frequency count to its list of nodes
    int maxSizeCache;               // capacity of cache
    int minFreq;                    // track minimum frequency in cache
    int curSize;                    // current size of cache

public:
    LFUCache(int capacity) {
        maxSizeCache = capacity;
        minFreq = 0;
        curSize = 0;
    }

    // Helper to update frequency map when a node is accessed
    void updateFreqListMap(Node *node) {
        // Remove node from current frequency list
        freqListMap[node->cnt]->removeNode(node);

        // If current list is empty and its frequency is minFreq, increment minFreq
        if (node->cnt == minFreq && freqListMap[node->cnt]->size == 0) {
            minFreq++;
        }

        // Move node to next higher frequency list
        List *nextHigherFreqList;
        if (freqListMap.find(node->cnt + 1) != freqListMap.end()) {
            nextHigherFreqList = freqListMap[node->cnt + 1];
        } else {
            nextHigherFreqList = new List();
        }

        node->cnt += 1;  // increase frequency
        nextHigherFreqList->addFront(node); // add to front (most recently used)
        freqListMap[node->cnt] = nextHigherFreqList; // update map
    }

    // Get value for a key, and update its usage frequency
    int get(int key) {
        if (keyNode.find(key) != keyNode.end()) {
            Node *node = keyNode[key];
            int val = node->value;
            updateFreqListMap(node); // update frequency
            return val;
        }
        return -1; // not found
    }

    // Put a new key-value pair into cache
    void put(int key, int value) {
        if (maxSizeCache == 0) return; // edge case: 0 capacity

        if (keyNode.find(key) != keyNode.end()) {
            // If key exists, update value and frequency
            Node *node = keyNode[key];
            node->value = value;
            updateFreqListMap(node);
        } else {
            // If cache is full, evict least frequently used node
            if (curSize == maxSizeCache) {
                List *list = freqListMap[minFreq];        // get min frequency list
                keyNode.erase(list->tail->prev->key);     // remove from key map
                list->removeNode(list->tail->prev);       // remove least recently used
                curSize--;
            }

            curSize++;
            minFreq = 1; // reset minFreq to 1 for new node

            List *listFreq;
            if (freqListMap.find(minFreq) != freqListMap.end()) {
                listFreq = freqListMap[minFreq];
            } else {
                listFreq = new List();
            }

            Node *node = new Node(key, value);
            listFreq->addFront(node);         // insert at front of list
            keyNode[key] = node;              // map key to node
            freqListMap[minFreq] = listFreq;  // map frequency to list
        }
    }
};