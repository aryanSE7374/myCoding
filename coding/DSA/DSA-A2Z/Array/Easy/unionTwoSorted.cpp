#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        int m = a.size();
        int n = b.size();
        int i=0,j=0;
        vector<int> unionArr;

        while(i<m && j<n){
            if(a[i]<=b[j]){
                if(unionArr.size()==0 || unionArr.back()!=a[i]){
                    unionArr.push_back(a[i]);
                }
                i++;
            }
            else{
                if(unionArr.size()==0 || unionArr.back()!=b[j]){
                    unionArr.push_back(b[j]);
                }
                j++;
            }
        }
        while (i<m)
        {
            if(unionArr.back()!=a[i]){
                unionArr.push_back(a[i]);
            }
            i++;
        }
        while (j<n)
        {
            if(unionArr.back()!=b[j]){
                unionArr.push_back(b[j]);
            }
            j++;
        }
        return unionArr;


        // Your code here
        // return vector with correct order of elements
    }
};