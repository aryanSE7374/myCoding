#include<bits/stdc++.h>
using namespace std;


// Function to perform selection sort on the given array.
void selectionSort(vector<int> &arr) {
    // code here
    for(int i = 0; i<=arr.size()-2 ; i++){
        int min = i;
        for(int j = i ; j<=arr.size()-1 ; j++){
            if(arr[j]<arr[min]){min = j;}
        }
        // swap
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

// Function to sort the array using bubble sort algorithm.
void bubbleSort(vector<int>& arr) {
    for (int i = arr.size()-1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}


// optimized bubble sort (for the best case)
void bubbleSortOpt(vector<int>& arr) {
    for (int i = arr.size()-1; i > 0; i--)
    {
        bool didSwap = false;
        for (int j = 0; j < i; j++)
        {
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                didSwap = true;
            }
        }
        if(!didSwap){
            return;
        }
    }
}


//insertion sort
// Please change the array in-place
void insertionSort(vector<int>& arr) {
    for (int i = 0; i <=arr.size()-2; i++)
    {
        for (int j = i+1; j>0; j--)
        {
            if(arr[j]<arr[j-1]){
                swap(arr[j] , arr[j-1]);
            }
            else{break;}
        }
    }
}

// striver's code
void insertion_sort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i <= n - 1; i++) {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j]) {
            //swap(arr[j] , arr[j-1]);
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;

            j--;
        }
    }
}



int main(){
    vector<int>(6) = {13, 46, 24, 52, 20, 9};
    return 0;
}