#include <bits/stdc++.h>
using namespace std;

// Function to heapify a subtree rooted at index i
// n is size of heap
// 0 based indexing
void heapify(vector<int> &arr, int n, int i) {
    int largest = i;           // Initialize largest as root
    int left = 2 * i + 1;      // Left child index
    int right = 2 * i + 2;     // Right child index

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than the current largest
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root, swap and continue heapifying
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Function to perform heap sort
void heapSort(vector<int> &arr) {
    int n = arr.size();

    // Step 1: Build a Max Heap (O(n))
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Step 2: Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--) {
        // Move current root (max element) to the end
        swap(arr[0], arr[i]);

        // Heapify reduced heap
        heapify(arr, i, 0);
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};

    cout << "Original array:\n";
    for (int val : arr)
        cout << val << " ";
    cout << endl;

    heapSort(arr);

    cout << "\nSorted array (Heap Sort using Max Heap):\n";
    for (int val : arr)
        cout << val << " ";
    cout << endl;

    return 0;
}