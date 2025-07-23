#include<bits/stdc++.h>
using namespace std;


// Brute : Generate all 2^N binary strings, then filter those without “11”

// TC : O(2ⁿ*N) 
// SC : O(N)


//--------------------------------------------------------------------------//

// my solution : 1
// TC : O(2ⁿ) :- draw recursion tree for rec relation : 
// T(N) = T(N-1) + T(N-2) , base case T(0) = T(1) = c
// SC : O(N)
// Total valid strings follow Fibonacci growth

class Solution {
  public:
    vector<string> generate(int N ) {
        if(N==0){return {};}

        if(N==1){
            return {"0" , "1"};
        }

        // optimized , not necessearily the base case
        if(N==2){
            return {"00" , "01" , "10"};
        }

        vector<string> res;

        vector<string> vec0 = generate(N-1);
        // string str0 = "0";
        for(auto s : vec0){
            res.push_back("0"+s);
        }

        vector<string> vec1 = generate(N-2);
        // string str1 = "10";
        for(auto s : vec1){
            res.push_back("10"+s);
        }

        return res;
    }

    vector<string> generateBinaryStrings(int num) {
        return generate(num);
    }

};

//--------------------------------------------------------------------------//

// Suggested Optimal (Backtracking-Based) Alternative
// Total valid strings follow Fibonacci growth


class Solution {
public:
    void helper(int n, string current, vector<string>& result, char prev) {
        if (n == 0) {
            result.push_back(current);
            return;
        }

        helper(n - 1, current + '0', result, '0');  // always valid
        if (prev != '1') {
            helper(n - 1, current + '1', result, '1');  // only if last was not '1'
        }
    }

    vector<string> generateBinaryStrings(int N) {
        vector<string> result;
        helper(N, "", result, '0');
        sort(result.begin(), result.end());  // for lexicographic order
        return result;
    }
};

//--------------------------------------------------------------------------//