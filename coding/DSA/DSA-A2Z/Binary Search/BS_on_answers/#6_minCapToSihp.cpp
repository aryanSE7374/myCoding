#include<bits/stdc++.h>
using namespace std;


// brute try 1 : wrong approach

class Solution {
    public:
    
        int sumWeights(vector<int>& weights){
            int sum = 0;
            for(auto it : weights){
                sum += it;
            }
            return sum;
        }
        bool canShipWithinDays(vector<int>& weights , int days , int maxCap){
            int n = weights.size();
            for(int i = 0 ; i < n ; i++){
                int currSum = 0;
                int currDays = 0;
                while(i<n && currSum <= maxCap){
                    currSum += weights[i];
                    i++;
                }
                currDays++;
                if(currDays>days){return false;}
            }
            return true;
        }
        int shipWithinDays(vector<int>& weights, int days) {
            int sum = sumWeights(weights); // 500 * 5000 < INT_MAX
            int maxi = *max_element(weights.begin() , weights.end());
    
            // i -> maximum capacity
            for(int i = maxi ; i < sum ; i ++ ){
                if(canShipWithinDays(weights , days , i)){return i;}
            }
            return maxi;
        }
    };



 // brute try 2 : produces TLE


class Solution {
    public:
    
        int sumWeights(vector<int>& weights){
            int sum = 0;
            for(auto it : weights){
                sum += it;
            }
            return sum;
        }
        bool canShipWithinDays(vector<int>& weights , int days , int maxCap){
            int n = weights.size();
            int reqDays = 0;
            for(int i = 0 ; i < n ; i++){
                int currSum = 0;
                int lastIndex = i;
                while(i<n && currSum <= maxCap){
                    currSum+=weights[i];
                    i++;
                    if(currSum<=maxCap){lastIndex++;}
                    else break;
                }
                i = lastIndex-1;
                reqDays++;
                if(reqDays>days){return false;}
            }
            return true;
        }
        int shipWithinDays(vector<int>& weights, int days) {
            int sum = sumWeights(weights); // 500 * 5000 < INT_MAX
            int maxi = *max_element(weights.begin() , weights.end());
    
            // i -> maximum capacity
            for(int i = maxi ; i <= sum ; i++ ){
                if(canShipWithinDays(weights , days , i)){return i;}
            }
            return maxi;
        }
    };




// optimal soln 1 : binary search

class Solution {
    public:
    
        int sumWeights(vector<int>& weights){
            int sum = 0;
            for(auto it : weights){
                sum += it;
            }
            return sum;
        }
        bool canShipWithinDays(vector<int>& weights , int days , int maxCap){
            int n = weights.size();
            int reqDays = 0;
            for(int i = 0 ; i < n ; i++){
                int currSum = 0;
                int lastIndex = i;
                while(i<n && currSum <= maxCap){
                    currSum+=weights[i];
                    i++;
                    if(currSum<=maxCap){lastIndex++;}
                    else break;
                }
                i = lastIndex-1;
                reqDays++;
                if(reqDays>days){return false;}
            }
            return true;
        }
        int shipWithinDays(vector<int>& weights, int days) {
            int sum = sumWeights(weights); // 500 * 5000 < INT_MAX
            int maxi = *max_element(weights.begin() , weights.end());


            // binary search : low will be the answer

            int low = maxi , high = sum;
            while(low<=high){
                int mid = (low+high)/2;
                if(canShipWithinDays(weights , days , mid)){high = mid-1 ;}
                else{low=mid+1;}
            }
            return low;
        }
    };

