#include<bits/stdc++.h>
using namespace std;

// GFG

// sol1
class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        sort(arr.begin() , arr.end());
        return arr[k-1];
    }
};

// sol2
class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        priority_queue<int , vector<int> , greater<int>> pq(arr.begin() , arr.end());
        for(int i=1 ; i<=k-1 ; i++){
            pq.pop();
        }
        return pq.top();
    }
};

// sol3

class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        int n = arr.size();

        priority_queue<int > pq(arr.begin() , arr.begin()+k);

        for(int i=k ; i<n ; i++){
            if(arr[i]<pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
        }

        return pq.top();
    }
};


// sol4 (extra : quick sort based approach)

//User function template for C++

class Solution{

    public:

    int pivtol(int array[],int start,int end){
     
        int position=start;
        
        for(int i=start; i<=end; i++){
            if(array[i]<=array[end]){
                swap(array[i],array[position]);
                position++;
            }
        }
            
        return position-1;    
        
    }

    void quicksort(int arr[],int start,int end,int k,int &ans){
        
        int pivot=pivtol(arr,start,end);
        if(pivot==k){
            ans=arr[k];
            return;
        }
        
        if(start<end){
        
            quicksort(arr,start,pivot-1,k,ans);
            quicksort(arr,pivot,end,k,ans);
        
        }
        
    }
   
    int kthSmallest(int arr[], int start, int end, int k) {
        
    int ans;    
    quicksort(arr,0,end,k-1,ans);
    
    return ans;
    
    }
};