#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int firstOccurrence(vector<int> &arr, int n, int k) {
            int low = 0, high = n - 1;
            int first = -1;
        
            while (low <= high) {
                int mid = (low + high) / 2;
                // maybe an answer
                if (arr[mid] == k) {
                    first = mid;
                    //look for smaller index on the left
                    high = mid - 1;
                }
                else if (arr[mid] < k) {
                    low = mid + 1; // look on the right
                }
                else {
                    high = mid - 1; // look on the left
                }
            }
            return first;
        }
        
        int lastOccurrence(vector<int> &arr, int n, int k) {
            int low = 0, high = n - 1;
            int last = -1;
        
            while (low <= high) {
                int mid = (low + high) / 2;
                // maybe an answer
                if (arr[mid] == k) {
                    last = mid;
                    //look for larger index on the right
                    low = mid + 1;
                }
                else if (arr[mid] < k) {
                    low = mid + 1; // look on the right
                }
                else {
                    high = mid - 1; // look on the left
                }
            }
            return last;
        }
    
        vector<int> searchRange(vector<int>& nums, int target) {
            vector<int> result(2,-1);
            int n = nums.size();
            int first = firstOccurrence(nums , n , target);
            if(first==-1){return result;}
            int last = lastOccurrence(nums , n , target);
            result[0]=first;
            result[1]=last;
            return result;
        }
};
    

// int firstOccurrence(vector<int> &arr, int n, int k) {
//     int low = 0, high = n - 1;
//     int first = -1;

//     while (low <= high) {
//         int mid = (low + high) / 2;
//         // maybe an answer
//         if (arr[mid] == k) {
//             first = mid;
//             //look for smaller index on the left
//             high = mid - 1;
//         }
//         else if (arr[mid] < k) {
//             low = mid + 1; // look on the right
//         }
//         else {
//             high = mid - 1; // look on the left
//         }
//     }
//     return first;
// }

// int lastOccurrence(vector<int> &arr, int n, int k) {
//     int low = 0, high = n - 1;
//     int last = -1;

//     while (low <= high) {
//         int mid = (low + high) / 2;
//         // maybe an answer
//         if (arr[mid] == k) {
//             last = mid;
//             //look for larger index on the right
//             low = mid + 1;
//         }
//         else if (arr[mid] < k) {
//             low = mid + 1; // look on the right
//         }
//         else {
//             high = mid - 1; // look on the left
//         }
//     }
//     return last;
// }


// pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k) {
//     int first = firstOccurrence(arr, n, k);
//     if (first == -1) return { -1, -1};
//     int last = lastOccurrence(arr, n, k);
//     return {first, last};
// }
