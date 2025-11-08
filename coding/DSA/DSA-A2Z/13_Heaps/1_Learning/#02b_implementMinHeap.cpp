//Q : Build Min Heap (code studio)
// code studio (minHeap) : https://www.naukri.com/code360/problems/build-min-heap_1171167

#include <bits/stdc++.h> 
using namespace std;



// sol 1 : my brute try

class heap {
public:
    vector<int> arr;
    int size;

    heap() {
        arr.resize(10000);
        size = 0;
    }

    heap(int n) {
        arr.resize(n);
        size = -1;
    }

    // TC: O(log n)
    void insert(int val) {
        size = size + 1;
        int index = size;
        arr[size] = val;

        // Move up while parent is greater (for min heap)
        while (index > 0) {
            int parent = (index - 1) / 2;

            if (arr[parent] > arr[index]) { // <-- flipped condition
                swap(arr[parent], arr[index]);
                index = parent;
            } else {
                return;
            }
        }
    }
};

vector<int> buildMinHeap(vector<int> &arr) {
    int n = arr.size();
    vector<int> res;
    heap h(n);

    for (int i = 0; i < n; i++) {
        h.insert(arr[i]);
    }

    // Copy only used portion of heap array
    res = vector<int>(h.arr.begin(), h.arr.begin() + h.size + 1);
    return res;
}



// ------------------------------------------------------------ //

// optimal solution using heapify

void heapify(vector<int> &arr, int n, int i){

    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    
    if(left < n && arr[smallest] > arr[left]){
        smallest = left;
    }

    if(right < n && arr[smallest] > arr[right]){
        smallest = right;
    }

    if(smallest != i){
        std::swap(arr[smallest], arr[i]);
        heapify(arr, n, smallest);
    }
}


vector<int> buildMinHeap(vector<int> &arr)
{
    int n = arr.size();
    for(int i=n/2-1; i>=0; i--){
        heapify(arr, n, i);
    }
    return arr;
}

// ------------------------------------------------------------ //