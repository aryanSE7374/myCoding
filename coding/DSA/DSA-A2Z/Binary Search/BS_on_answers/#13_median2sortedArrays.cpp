#include<bits/stdc++.h>
using namespace std;

// try 1

// class Solution {
//     public:
//         double findMedianEven(vector<int>&nums1 ,vector<int>& nums2 , int m , int n ){
//             int lastIndex = (m+n)/2;
//             int l=0, r=0;
//             while(l+r+2 < lastIndex){
//                 if(nums1[l]<nums2[r]){l++;}
//                 else{r++;}
//             }
//             return ((double)nums1[l] + (double)nums2[r])/(double)2;
//         }
//         double findMedianOdd(vector<int>&nums1 ,vector<int>& nums2 , int m , int n ){
//             int lastIndex = (m+n+2)/2;
//             int l=0, r=0;
//             while(l+r+2 < lastIndex){
//                 if(nums1[l]<nums2[r]){l++;}
//                 else{r++;}
//             }
//             return (double)max(nums1[l] , nums2[r]);
//         }

//         double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//             int m = nums1.size();
//             int n = nums2.size();
//             if((m+n)^1==0){return findMedianEven(nums1 , nums2 , m , n );}
//             else return findMedianOdd(nums1 , nums2 , m , n );
//         }
//     };



// brute :-  TC : O(n1+n2) , SC : O(n1+n2)

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    //size of two given arrays:
    int n1 = nums1.size(), n2 = nums2.size();
    vector<int> arr3;
    //apply the merge step:
    int i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (nums1[i] < nums2[j]) arr3.push_back(nums1[i++]);
        else arr3.push_back(nums2[j++]);
    }

    //copy the left-out elements:
    while (i < n1) arr3.push_back(nums1[i++]);
    while (j < n2) arr3.push_back(nums2[j++]);

    //Find the median:
    int n = n1 + n2;
    if (n % 2 == 1) {
        return (double)arr3[n / 2];
    }

    double median = ((double)arr3[n / 2] + (double)arr3[(n / 2) - 1]) / 2.0;
    return median;
}

 
// better : (using a count variable) -> try2  to approach TC : O(n1+n2) , SC : O(1)
/*
class Solution {
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            //size of two given arrays:
            int n1 = nums1.size(), n2 = nums2.size();
            int n = n1+n2;
            int p1=0;
            int p2=0;
            int count = 2;
            while (count<(n+1)/2)
            {
                if(p1<n1 && p2<n2){
                    if(nums1[p1]<nums2[p2]){p1++;count++;}
                    else{p2++;count++;}
                }
                else if(p1>=n1){p2++;count++;}
                else{p1++;count++;}
                // count++; // remove all count++ statements
            }
            // now the max(nums1[p1],nums2[p2]) will point to the first/only median element

            if(n&1==0){//even
                if(p1<n1 && p2<n2){
                    int ans1 = max(nums1[p1],nums2[p2]);
                    if(nums1[p1]<nums2[p2]){p1++;count++;}
                    else{p2++;count++;}
                    int ans2 = max(nums1[p1],nums2[p2]);
                    return ((double)ans1 + (double)ans2)/2.0;
                }
                else if(p1>=n1){
                    int ans1 = nums2[p2];
                    int ans2 = nums2[p2+1];
                    return ((double)ans1 + (double)ans2)/2.0;
                }
                else{
                    int ans1 = nums2[p1];
                    int ans2 = nums2[p1+1];
                    return ((double)ans1 + (double)ans2)/2.0;
                }
            }
            else{//odd
                if(p1<n1 && p2<n2){
                    return (double)(max(nums1[p1],nums2[p2]));
                }
                else if(p1>=n1){
                    return nums2[p2];
                }
                else{
                    return nums1[p1];
                }
                // return (double)(max(nums1[p1],nums2[p2]));
            }
        }
    };
*/

// better approach by striver : TC : O(n1+n2) , SC : O(1)
class Solution {
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            int i=0;
            int j=0;
            //size of two given arrays:
            int n1 = nums1.size(), n2 = nums2.size();
            int n = n1+n2; // total no. of elements in the merged sorted array
            /* track of current index and hence the element to be at that index 
            in the merged sorted array */
            int idxcnt=0;
            int idx1 = (n/2)-1;
            int idx2 = n/2;
            int idx1el = -1;
            int idx2el = -1;

            // start linear search for the elements idx1el and idx2el
            while (i<n1 && j<n2)
            {
                if(nums1[i]<nums2[j]){
                    if(idxcnt==idx1){idx1el=nums1[i];}
                    if(idxcnt==idx2){idx2el=nums1[i];}
                    i++;
                    idxcnt++;
                }
                else{
                    if(idxcnt==idx1){idx1el=nums2[j];}
                    if(idxcnt==idx2){idx2el=nums2[j];}
                    j++;
                    idxcnt++;
                }
            }
            while (i<n1)
            {
                if(idxcnt==idx1){idx1el=nums1[i];}
                if(idxcnt==idx2){idx2el=nums1[i];}
                i++;
                idxcnt++;
            }
            while (j<n2)
            {
                if(idxcnt==idx1){idx1el=nums2[j];}
                if(idxcnt==idx2){idx2el=nums2[j];}
                j++;
                idxcnt++;
            }
            if (n%2==0)
            {
                return ((double)idx1el + (double)idx2el)/2.0;
            }
            else{
                return (double)idx2el;
            }
        }
    };

// try 3 : to optimize binary search

