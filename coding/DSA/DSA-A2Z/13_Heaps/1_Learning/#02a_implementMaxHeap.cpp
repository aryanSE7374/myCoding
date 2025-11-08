#include <bits/stdc++.h> 
using namespace std;


// code studio (maxHeap) : https://www.naukri.com/code360/problems/build-heap_975375

// sol 1 : my brute try

class heap {
    public:
    vector<int> arr;
    int size;

	heap(){
		arr.resize(10000);
        // arr[0] = -1;
        size = 0;
    }

    heap(int n){
		// n = max size
		arr.resize(n);
        // arr[0] = -1;
        size = -1;
    }

    // TC -> O(log) -> since we are comparing value with i/2 index
    void insert(int val){
        size = size + 1;
        int index = size;
        arr[size] = val;

        while(index > 0){
            int parent = (index-1)/2;

            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }else{
                return;
            }
        }
    }
};

vector<int> buildHeap(vector<int> arr, int n)
{	
	// Write your code here 

	vector<int> res;
	heap h(n);
	for(int i=0 ; i<n ; i++){
		h.insert(arr[i]);
	}
	res = vector<int>(h.arr.begin(), h.arr.begin() + h.size + 1);
    return res;
}



// ------------------------------------------------------------ //

// optimal solution using heapify

// Function to heapify a subtree rooted at index i
// n is the size of the heap (array length)
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;           // Assume current node is largest
    int left = 2 * i + 1;      // Left child index
    int right = 2 * i + 2;     // Right child index

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than the current largest
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
        // Recursively heapify the affected subtree
        heapify(arr, n, largest);
    }
}

// Builds a max heap from the given array
vector<int> buildHeap(vector<int> arr, int n) {
    // Start from the last non-leaf node and heapify each node
    for (int i = (n / 2) - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    return arr;
}


// ------------------------------------------------------------ //


int main(){

    vector<int> arr = {70,55,56,45,50,24,67,88,12,45,23,54};


    vector<int> res = buildHeap(arr,arr.size());

    for(int num : res){
        cout << num << " ";
    }

    cout<<endl;


    return 0;
}