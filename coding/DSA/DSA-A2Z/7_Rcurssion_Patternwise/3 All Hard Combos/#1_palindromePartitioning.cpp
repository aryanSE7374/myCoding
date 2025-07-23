#include<bits/stdc++.h>
using namespace std;


// Brute Force Solution : generate all substrings and then check for palindrome (if yes , then add to result)
// TC : O(n × 2^n)
// SC : O(n × 2^n)

// ------------------------------------------------------------------------------------------------------------------------------------ // 

// striver's backtracking solution
// TC : O(n × 2^n)
// SC : O(n × 2^n)

class Solution {
public:
    bool isPalindrome(string s , int l , int h){
        while(l<=h){
            if(s[l]!=s[h]){return false;}
            l++;h--;
        }
        return true;
    }

    void partitionHelper(int index , string s , vector<string> path , vector<vector<string>>& ans , int n){
        if(index == n){
            ans.push_back(path);
            return;
        }

        for(int i=index ; i<n ; ++i){

            if(isPalindrome(s , index , i)){

                path.push_back(s.substr(index , i-index+1)); // since len of the substr (from index to ith) = i-index+1

                partitionHelper(i+1 , s , path , ans , n);

                path.pop_back(); // backtrack step

            }
        }

    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        int n = s.length();
        partitionHelper(0 , s , {} , ans , n);
        return ans;
    }
};

// ------------------------------------------------------------------------------------------------------------------------------------ // 

// DP solution : by chat GPT
// DP + Backtracking Solution
// TC : O(n^2 + n × 2^n)
// SC : O(n^2 + n × 2^n)

class Solution {
public:
    void backtrack(int start, string& s, vector<string>& path, vector<vector<string>>& ans, vector<vector<bool>>& dp) {
        int n = s.size();
        if (start == n) {
            ans.push_back(path);
            return;
        }

        for (int end = start; end < n; ++end) {
            if (dp[start][end]) {
                path.push_back(s.substr(start, end - start + 1));
                backtrack(end + 1, s, path, ans, dp);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        // Fill DP table
        for (int len = 1; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    if (len <= 2)
                        dp[i][j] = true;
                    else
                        dp[i][j] = dp[i + 1][j - 1];
                }
            }
        }

        vector<vector<string>> ans;
        vector<string> path;
        backtrack(0, s, path, ans, dp);
        return ans;
    }
};

// ------------------------------------------------------------------------------------------------------------------------------------ // 