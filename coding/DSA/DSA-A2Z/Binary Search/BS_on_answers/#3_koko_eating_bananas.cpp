#include<bits/stdc++.h>
using namespace std;


// today : 26 march 



// brute force : have overflow issues

class Solution {
    public:
        int maxVal(vector<int>& arr,int n){
            int maxi = INT_MIN;
            for(int i=0 ; i<n ; i++){
                maxi = max (maxi , arr[i]);
            }
            return maxi;
        }
        int reqTime(vector<int>& arr ,int n , int k){
            int totalHrs = 0;
            for(int i = 0 ; i<n ; i++){
                totalHrs = totalHrs + ceil(double(arr[i])/double(k));
            }
            return totalHrs;
        }
        int minEatingSpeed(vector<int>& piles, int h) {
            int n = piles.size();
            int maxValue = maxVal(piles , n);
            for(int k=1 ; k<= maxValue ; k++){
                int totalTime = reqTime(piles , n , k) ;
                if(totalTime<=h){return k;}
            }
            return maxValue;
        }
    };



// better : overcomes voerflow issues but produces TLE

class Solution {
    public:
        int maxVal(vector<int>& arr,int n){
            int maxi = INT_MIN;
            for(int i=0 ; i<n ; i++){
                maxi = max (maxi , arr[i]);
            }
            return maxi;
        }
        int minEatingSpeed(vector<int>& piles, int h) {
            int n = piles.size();
            int maxValue = maxVal(piles , n);
            for(int k=1 ; k<= maxValue ; k++){
                // int totalTime = reqTime(piles , n , k) ;
                int totalHrs = 0;
                for(int i = 0 ; i<n ; i++){
                    totalHrs = totalHrs + ceil(double(piles[i])/double(k));
                    if(totalHrs>h){break;}
                }
                if(totalHrs<=h){return k;}
            }
            return maxValue;
        }
    };



// optimal : overflow with problems

class Solution {
    public:
        int maxVal(vector<int>& arr,int n){
            int maxi = INT_MIN;
            for(int i=0 ; i<n ; i++){
                maxi = max (maxi , arr[i]);
            }
            return maxi;
        }
        int reqTime(vector<int>& arr ,int n , int k){
            int totalHrs = 0;
            for(int i = 0 ; i<n ; i++){
                totalHrs = totalHrs + ceil(double(arr[i])/double(k));
            }
            return totalHrs;
        }
        int minEatingSpeed(vector<int>& piles, int h) {
            int n = piles.size();
            int maxValue = maxVal(piles , n);

            // binary search on range 1 to maxValue
            int low=1,high=maxValue;
            while(low<=high){
                int mid = (low+high)/2;
                int totalTime = reqTime(piles , n , mid) ;
                if(totalTime<=h){
                    high = mid-1;
                }
                else{low=mid+1;}
            }
            return low;
        }
    };




// optimal : without overflow problems

class Solution {
    public:
        int maxVal(vector<int>& arr,int n){
            int maxi = INT_MIN;
            for(int i=0 ; i<n ; i++){
                maxi = max (maxi , arr[i]);
            }
            return maxi;
        }
        int minEatingSpeed(vector<int>& piles, int h) {
            int n = piles.size();
            int maxValue = maxVal(piles , n);

            // binary search on range 1 to maxValue
            int low=1,high=maxValue;
            while(low<=high){
                int mid = (low+high)/2;
                // int totalTime = reqTime(piles , n , mid) ;
                // inline optimization on totalTime function
                int totalHrs = 0;
                for(int i = 0 ; i<n ; i++){
                    totalHrs = totalHrs + ceil(double(piles[i])/double(mid));
                    if(totalHrs>h){break;}
                }
                if(totalHrs<=h){
                    high = mid-1;
                }
                else{low=mid+1;}
            }
            return low; // VERY IMPORTANT LINE
        }
    };


// class Solution {
//     public:
//         int findMax(vector<int> &v) {
//             int maxi = INT_MIN;
//             int n = v.size();
//             //find the maximum:
//             for (int i = 0; i < n; i++) {
//                 maxi = max(maxi, v[i]);
//             }
//             return maxi;
//         }
        
//         int calculateTotalHours(vector<int> &v, int hourly) {
//             int totalH = 0;
//             int n = v.size();
//             //find total hours:
//             for (int i = 0; i < n; i++) {
//                 totalH += ceil((double)(v[i]) / (double)(hourly));
//             }
//             return totalH;
//         }
//         int minEatingSpeed(vector<int>& piles, int h) {
//             int low = 1, high = findMax(piles);
    
//             //apply binary search:
//             while (low <= high) {
//                 int mid = (low + high) / 2;
//                 int totalH = calculateTotalHours(piles, mid);
//                 if (totalH <= h) {
//                     high = mid - 1;
//                 }
//                 else {
//                     low = mid + 1;
//                 }
//             }
//             return low;
//         }
//     };

// #include <vector>
// #include <algorithm>
// #include <cmath>
// using namespace std;

// class Solution {
// public:
//     int findMax(vector<int>& v) {
//         int maxi = INT_MIN;
//         int n = v.size();
//         // Find the maximum:
//         for (int i = 0; i < n; i++) {
//             maxi = max(maxi, v[i]);
//         }
//         return maxi;
//     }

//     int calculateTotalHours(vector<int>& v, int hourly) {
//         int totalH = 0;
//         int n = v.size();
//         // Find total hours:
//         for (int i = 0; i < n; i++) {
//             totalH += (v[i] + hourly - 1) / hourly; // Avoid floating-point operations
//         }
//         return totalH;
//     }

//     int minEatingSpeed(vector<int>& piles, int h) {
//         int low = 1, high = findMax(piles);

//         // Apply binary search:
//         while (low <= high) {
//             int mid = (low + high) / 2;
//             int totalH = calculateTotalHours(piles, mid);
//             if (totalH <= h) {
//                 high = mid - 1;
//             } else {
//                 low = mid + 1;
//             }
//         }
//         return low;
//     }
// };



    // int findMax(vector<int> &v) {
    //     int maxi = INT_MIN;
    //     int n = v.size();
    //     //find the maximum:
    //     for (int i = 0; i < n; i++) {
    //         maxi = max(maxi, v[i]);
    //     }
    //     return maxi;
    // }
    
    // int calculateTotalHours(vector<int> &v, int hourly) {
    //     int totalH = 0;
    //     int n = v.size();
    //     //find total hours:
    //     for (int i = 0; i < n; i++) {
    //         totalH += ceil((double)(v[i]) / (double)(hourly));
    //     }
    //     return totalH;
    // }
    
    // int minimumRateToEatBananas(vector<int> v, int h) {
    //     int low = 1, high = findMax(v);
    
    //     //apply binary search:
    //     while (low <= high) {
    //         int mid = (low + high) / 2;
    //         int totalH = calculateTotalHours(v, mid);
    //         if (totalH <= h) {
    //             high = mid - 1;
    //         }
    //         else {
    //             low = mid + 1;
    //         }
    //     }
    //     return low;
    // }



