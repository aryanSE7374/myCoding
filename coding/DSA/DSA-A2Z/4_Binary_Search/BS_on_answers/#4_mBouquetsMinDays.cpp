#include<bits/stdc++.h>
using namespace std;

/*
You are given an integer array bloomDay, an integer m and an integer k.

You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.

The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.

Return the minimum number of days you need to wait to be able to make m bouquets from the garden. 
If it is impossible to make m bouquets return -1.
*/


// brute : produces TLE [ O((maxi-mini+1)*n) ]

class Solution {
    public:
        int canMakeBouquets(vector<int>& bloomDay , int day , int m , int k){
            int totalBouquets = 0;
            int counter = 0;
            int n = bloomDay.size();
            for(int i=0 ; i < n ; i++){
                if(bloomDay[i] <= day){counter++;}
                else{
                    totalBouquets += (counter/k);
                    counter=0;
                }
            }
            totalBouquets += (counter/k);
            return (totalBouquets>=m);
            // if(totalBouquets>=m){return true;}
            // return false;
        }
        int minDays(vector<int>& bloomDay, int m, int k) {
            int mini = *min_element(bloomDay.begin(),bloomDay.end());
            int maxi = *max_element(bloomDay.begin(),bloomDay.end());
            for (int i = mini; i <= maxi; i++)
            {
                if(canMakeBouquets(bloomDay , i , m , k )){return i;}   
            }
            return -1;
        }
    };


// optimal


class Solution {
    public:
        int canMakeBouquets(vector<int>& bloomDay , int day , int m , int k){
            int totalBouquets = 0;
            int counter = 0;
            int n = bloomDay.size();
            for(int i=0 ; i < n ; i++){
                if(bloomDay[i] <= day){counter++;}
                else{
                    totalBouquets += (counter/k);
                    counter=0;
                }
            }
            totalBouquets += (counter/k);
            return (totalBouquets>=m);
            // if(totalBouquets>=m){return true;}
            // return false;
        }
        int minDays(vector<int>& bloomDay, int m, int k) {
            int mini = *min_element(bloomDay.begin(),bloomDay.end());
            int maxi = *max_element(bloomDay.begin(),bloomDay.end());

            int low = mini;
            int high = maxi;

            int ans = -1;
            while(low<=high){
                int mid = (low+high)/2;
                if(!canMakeBouquets(bloomDay , mid , m , k )){
                    low = mid+1;
                }
                else{
                    ans = mid;
                    high = mid-1;
                }
            }

            // for (int i = mini; i <= maxi; i++)
            // {
            //     if(canMakeBouquets(bloomDay , i , m , k )){return i;}   
            // }
            return ans;
        }
    };