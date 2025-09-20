#include<bits/stdc++.h>
using namespace std;

string longestPalindrome(string s) {
    int n = s.length();
    if (n <= 1) return s;

    vector<vector<bool>> dp(n, vector<bool>(n, false)); // DP table
    int start = 0;
    int maxLen = 1; // At least 1 character is a palindrome

    for (int l = 1; l <= n; l++) {  // l = length of substring
        for (int i = 0; i <= n - l; i++) {  // start index
            int j = i + l - 1;  // end index

            if (i == j) {
                dp[i][j] = true;  // Single char is palindrome
            } 
            else if (j == i + 1) {
                dp[i][j] = (s[i] == s[j]); // Two chars: check if equal
            } 
            else {
                dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];
            }

            if (dp[i][j] && l > maxLen) {
                start = i;
                maxLen = l;
            }
        }
    }

    return s.substr(start, maxLen);
}
