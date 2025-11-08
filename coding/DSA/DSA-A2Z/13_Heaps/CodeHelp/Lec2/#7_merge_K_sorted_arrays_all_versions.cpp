#include<bits/stdc++.h>
using namespace std;



// GFG(easy version) : https://www.geeksforgeeks.org/problems/merge-k-sorted-arrays/1

class Solution {
  public:
    vector<int> mergeArrays(vector<vector<int>> &mat) {

        int n = mat.size();
        int m = mat[0].size();

        vector<int> res(n*m);

        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                res[(m*i)+j] = mat[i][j];
            }
        }

        sort(res.begin(),res.end());
        return res;

    }
};

// ------------------------------------------------------------ //





// ------------------------------------------------------------ //

// code 360 version
// https://www.naukri.com/code360/problems/merge-k-sorted-arrays_975379

// brute sol : accepted

#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>& mat , int k)
{
    int n = mat.size();

    vector<int> res;

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<mat[i].size() ; j++){
            res.push_back(mat[i][j]) ;
        }
    }

    sort(res.begin(),res.end());
    return res;
}


// ------------------------------------------------------------ //

// optimal solution : code help


#include <bits/stdc++.h> 

class node{
    public:
        int data;
        int i; 
        int j;

        node(int d, int row, int col){
            this -> data = d;
            i = row;
            j = col;
        }
};

class compare{
    public:
        bool operator()(node*a, node*b){
            return a -> data > b -> data;
        }
};

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<node*, vector<node*>, compare> minHeap;

    //step-1 : Insert all first element of k-arrays into minHeap
    //TC => O(klogk)
    for(int i=0; i<k; i++){
        node* temp = new node(kArrays[i][0], i, 0);
        minHeap.push(temp);
    }

    //step-2 : insert next element of same array into ans
    vector<int> ans;

    while(minHeap.size() > 0){
        node* temp = minHeap.top();

        ans.push_back(temp -> data);
        minHeap.pop();

        int i = temp -> i;
        int j = temp -> j;

        if(j+1 < kArrays[i].size()){
            node* next = new node(kArrays[i][j+1], i, j+1);
            minHeap.push(next); 
        }
    }
    return ans;
}




