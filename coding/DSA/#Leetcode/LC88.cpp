#include<bits/stdc++.h>
using namespace std;

// merge two sorted arrays

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int l=0; int r=0; // two pointers
        vector<int> aux;
        while ((l<m)&&(r<n))
        {
            if (nums1[l] <= nums2[r])
            {
                aux.push_back(nums1[l]); 
                l++;
            }
            else{
                aux.push_back(nums2[r]);
                r++;
            }
        }
        while (l<m)
        {
            aux.push_back(nums1[l]);
            l++;
        }
        while (r<n)
        {
            aux.push_back(nums2[r]);
            r++;
        }
        for(int i=0 ; i<(m+n) ; i++){
            // cout<<i<<":"<<nums1[i]<<"<-"<<aux[i]<<endl;
            nums1[i] = aux[i];
        }
    }
};