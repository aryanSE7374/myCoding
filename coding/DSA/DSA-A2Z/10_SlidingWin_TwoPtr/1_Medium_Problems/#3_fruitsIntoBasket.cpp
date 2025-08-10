#include<bits/stdc++.h>
using namespace std;

// striver's sol 1

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int maxLen=0;
        int l=0,r=0;
        unordered_map<int , int> mpp;

        while(r<n){
            mpp[fruits[r]]++;
            if(mpp.size()>2){
                while (mpp.size()>2)
                {
                    mpp[fruits[l]]--;
                    if(mpp[fruits[l]]==0){mpp.erase(fruits[l]);}
                    l++;
                }    
            }
            if(mpp.size()<=2){
                maxLen = max(maxLen , r-l+1);
            }
            r++;
        }
        return maxLen;
    }
};

// sol 1 - better

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int maxLen = 0;
        int l = 0, r = 0;
        unordered_map<int, int> mpp;

        while (r < n) {
            mpp[fruits[r]]++;

            while (mpp.size() > 2) {
                mpp[fruits[l]]--;
                if (mpp[fruits[l]] == 0) {
                    mpp.erase(fruits[l]); 
                }
                l++;
            }

            maxLen = max(maxLen, r - l + 1);
            r++;
        }

        return maxLen;
    }
};


// striver - sol-2 optimal

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int maxLen = 0;
        int l = 0, r = 0;
        unordered_map<int, int> mpp;

        while (r < n) {
            mpp[fruits[r]]++;

            if (mpp.size() > 2) {
                mpp[fruits[l]]--;
                if (mpp[fruits[l]] == 0) {
                    mpp.erase(fruits[l]); 
                }
                l++;
            }

            if(mpp.size()<=2){
                maxLen = max(maxLen , r-l+1);
            }
            r++;
        }

        return maxLen;
    }
};