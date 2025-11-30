#include<bits/stdc++.h>
using namespace std;

// GFG version -> fixed coins ; can be solved greedily !!
// https://www.geeksforgeeks.org/problems/-minimum-number-of-coins4426/1
// accepted

class Solution {
  public:
    int findMin(int n) {
        
        int amount = n;
        
        vector<int> coins = {10,5,2,1};
        
        if(amount == 0) return 0;

        // sort(coins.begin() , coins.end() , greater<int>() );
        int ans  = 0; 

        for(int coin : coins){
            if(coin <= amount){
                ans += (amount/coin);
                amount %= coin;
            }
            // if(amount<=0) break;
        }

        // return amount==0 ? ans : -1;
        return ans;
        
    }
};



// leetcode version -> variable coins ; cant be solved greedily ; DP required

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        if(amount == 0) return 0;

        sort(coins.begin() , coins.end() , greater<int>() );
        int ans  = 0; 

        for(int coin : coins){
            if(coin <= amount){
                ans += (amount/coin);
                amount %= coin;
            }
        }

        return amount==0 ? ans : -1;

    }
};