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

// try 3 : to optimize binary search : ___

// striver's optimal solution

class Solution {
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            
            /*
                              ||
            arr1_left .... l1 || r1 .... arr1_right 
            arr2_left .... l2 || r2 .... arr2_right
                              ||
            */

            // when even , search for l1,l2 ; when odd assume left side els > right side els

            int n1 = nums1.size();
            int n2 = nums2.size();
            
            //assuming that n1<=n2 ; i.e. searching the smaller array for optimization
            if(n1>n2){return findMedianSortedArrays(nums2,nums1);}

            int n = n1 + n2; // total no. of elements in combined array
            // search range : 0 to n1-1
            int low = 0; 
            int high = n1;
            int left = (n+1)/2; // total no. of els to be taken from left side   
            //(i.e. arr1_left + arr2_left )
            // middle element in case of odd , and in case of even : the no. of elemets to be taken on left side

            while (low<=high)
            {
                // mid1 : no. of els to be taken from arr1
                int mid1 = (low+high)>>1; //(low+high)/2
                // mid2 : no. of els to be taken from arr2
                int mid2 = left - mid1;

                // corner elements to be compared
                int l1 = INT_MIN , l2 = INT_MIN;
                int r1 = INT_MAX , r2 = INT_MAX;

                // mid1 , mid2 corresponds to the indics of r1 , r2
                if(mid1<n1) r1 = nums1[mid1];
                if(mid2<n2) r2 = nums2[mid2];

                // checking edge case to assign values of l1 , l2
                if(mid1-1 >= 0) l1 = nums1[mid1-1];
                if(mid2-1 >= 0) l2 = nums2[mid2-1];

                // success condtion : the only case to be considered
                if((l1 <= r2) && (l2 <= r1) ){
                    
                    if(n%2==1){ // if odd
                        return max(l1,l2);
                    }
                    else{ // else => if even
                        return (double)(max(l1,l2)+min(r1,r2))/2.0;
                    }
                }

                // eliminating the right half : take less elements from nums1
                else if(l1>r2){
                    high = mid1 - 1;
                }

                // eliminating the left half : take more elements from nums1
                else{
                    low = mid1 + 1;
                }
            }
            return 0; // dummy return
        }
    };



