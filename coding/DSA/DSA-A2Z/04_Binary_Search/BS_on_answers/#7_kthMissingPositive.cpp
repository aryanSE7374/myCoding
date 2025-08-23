#include<bits/stdc++.h>
using namespace std;



// brute force : O(N)

class Solution {
    public:
        int findKthPositive(vector<int>& arr, int k) {
            if(arr[0]-1 >= k){return k;}
            int count = arr[0]-1; // no. of missing interegrs
            int n = arr.size();
            for(int i=1 ; i<n ; i++){
                if(arr[i]-arr[i-1]>1){
                    if((count + (arr[i]-arr[i-1]-1)) > k){
                        return (arr[i-1]+(k-count));
                    }
                    count += (arr[i]-arr[i-1]-1);
                    if(count==k){return arr[i]-1;}
                }
            }
            return arr[n-1] + k - count;
        }
    };


// Brute : striver's clean and simple solution : need to mug it up (if less time)
class Solution {
    public:
        int findKthPositive(vector<int>& arr, int k) {
            if(k<arr[0]){return k;}
            int i=0;
            int n = arr.size();
            while (i<n && k>=arr[i])
            {
                i++;
                k++;
            }
            return k;
        }
    };


// applying binary search on interval 0 to n-1 to find the consecutive pairs

class Solution {
    public:
        int findKthPositive(vector<int>& arr, int k) {
            int low = 0;
            int high = arr.size() - 1;
            while (low<=high)
            {
                int mid = (low+high)/2;
                int missing = arr[mid]-mid-1;
                if(missing<k){low=mid+1;}
                else{high=mid-1;}
            }
            // int more = k - missing; // k - (arr[high]-high-1)
            // return arr[high] + more; // arr[high] + k - arr[high] + high + 1 = k+high+1
            return high+k+1;
        }
    };
    