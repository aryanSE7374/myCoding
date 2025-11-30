#include<bits/stdc++.h>
using namespace std;

// try1 : wrong approach

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> freq(20001 , 0);
        for(int rating : ratings){
            freq[rating]++;
        }
        int k = 1;
        int ans = 0;
        for(int i=0 ; i<20001 ; i++){
            if(freq[i]>0){
                ans += (k*freq[i]);
                k++;
            }
        }
        return ans;
    }
};

// ------------------------------------------------------------ //

// appraoch 2 (BRUTE) : O(N^2) - TLE

class Solution {
public:
    int candy(vector<int>& ratings) {
        
        bool flag = false;

        int n = ratings.size();

        vector<int> c(n,1); // candy assignemnts array

        do{

            flag = false;

            for(int i=0 ; i<n-1 ; i++){
                if(ratings[i] > ratings[i+1] && c[i] <= c[i+1] ){
                    c[i]++;
                    flag = true;
                }
            }

            for(int i=n-1 ; i>0 ; i--){
                if(ratings[i] > ratings[i-1] && c[i] <= c[i-1] ){
                    c[i]++;
                    flag = true;
                }
            }

        } while (flag);

        
        int sum = 0;

        for(int candy : c){
            sum += candy;
        }

        return sum;

    }
};

// ------------------------------------------------------------ //

// appraoch 3 (BETTER) : Striver's Greedy 1
// TC : O(3N) 
// SC : O(2N)

class Solution {
public:
    int candy(vector<int>& ratings) {

        int n = ratings.size();

        vector<int> left(n,1);
        vector<int> right(n,1);

        left[0] = 1;
        right[n-1] = 1;

        for(int i=1 ; i<n ; i++){
            if(ratings[i] > ratings[i-1]) left[i] = left[i-1] + 1;
            else left[i] = 1;
        }

        for(int i=n-2 ; i>=0 ; i--){
            if(ratings[i] > ratings[i+1]) right[i] = right[i+1] + 1;
            else right[i] = 1;
        }
        
        int sum = 0;

        for(int i=0 ; i<n ; i++){
            sum += max(left[i] , right[i]);
        }

        return sum;

    }
};

// ------------------------------------------------------------ //


// appraoch 3 BETTER(optimized) : Striver's Greedy 2
// TC : O(2N) 
// SC : O(N)

class Solution {
public:
    int candy(vector<int>& ratings) {

        int n = ratings.size();

        vector<int> left(n,1);
        // vector<int> right(n,1);

        left[0] = 1;
        // right[n-1] = 1;

        for(int i=1 ; i<n ; i++){

            if(ratings[i] > ratings[i-1]) left[i] = left[i-1] + 1;
            else left[i] = 1;

        }

        int sum = max(1,left[n-1]);
        int curr = 1 , right = 1;

        for(int i=n-2 ; i>=0 ; i--){

            if(ratings[i] > ratings[i+1]) curr = right+1;
            else curr = 1; 

            right = curr;

            sum += max(curr , left[i]);

        }

        return sum;

    }
};

// ------------------------------------------------------------ //
// approach 4 : optimal

class Solution {
public:
    int candy(vector<int>& ratings) {
        
    }
};
