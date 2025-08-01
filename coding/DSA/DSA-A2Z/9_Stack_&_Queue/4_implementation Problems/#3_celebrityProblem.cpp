#include<bits/stdc++.h>
using namespace std;


// bnrute sol by striver (leetcode style)
// Time: O(N^2) | Space: O(N)

class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        // brute
        int n = mat.size();
        vector<int> knowsMe(n , 0); 
        vector<int> iKnows(n,0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(mat[i][j]){
                    iKnows[i]++;
                    knowsMe[j]++;
                }
            }
        }
        for(int i=0 ; i<n ; i++){
            if(knowsMe[i]==n-1 && iKnows[i]==0){return i;}
        }
        return -1;
    }
};


// ------------------------------------------------------------------------------------------------------------------------------------ // 

// optimal solution : striver (leetcode style)
// Time: O(N) | Space: O(1)

class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        int n = mat.size();
        int top=0 ; int down = n-1;

        while (top<down)
        {
            if(mat[top][down]){
                top++;
            }
            else if(mat[down][top]){
                down--;
            }
            else{
                top++;
                down--;
            }
        }

        if(top>down){return -1;} // no possibe=le candidate for celebrity
        
        // verify candidate
        for(int i=0 ; i<n ; i++){
            if(i==top){continue;}
            if( mat[top][i]==0 && mat[i][top]==1 ){continue;}
            else{return -1;}
        }
        return top;
    }
};

/*
    using negation of conditions in verify candidate loop
    for (int i = 0; i < n; ++i) {
        if (i == cand) continue;
        if (mat[cand][i] == 1 || mat[i][cand] == 0)
            return -1;
    }
*/


// ------------------------------------------------------------------------------------------------------------------------------------ // 

// https://www.geeksforgeeks.org/problems/the-celebrity-problem/1
// GFG style solutions 

// chatGPT brute

// Time: O(N^2) | Space: O(1)
class Solution {
public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        for (int i = 0; i < n; i++) {
        bool knowsSomeone = false;
        for (int j = 0; j < n; j++) {
            if (i != j && mat[i][j]) {
                knowsSomeone = true;
                break;
            }
        }
        if (knowsSomeone) continue;

        bool isKnownByAll = true;
        for (int j = 0; j < n; j++) {
            if (i != j && mat[j][i] == 0) {
                isKnownByAll = false;
                break;
            }
        }

        if (isKnownByAll) return i;
    }
        return -1;
    }
};


// chatGPT better
// Time: O(N^2) | Space: O(N)
class Solution {
public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<int> in(n, 0), out(n, 0);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j && mat[i][j]) {
                    out[i]++;
                    in[j]++;
                }
                // if (mat[i][j]) {
                //     out[i]++;
                //     in[j]++;
                // }
            }
        }

        for (int i = 0; i < n; ++i) {
            if (in[i] == n - 1 && out[i] == 0)
                return i;
        }

        return -1;
    }
};



// stack based optimal (works on leetcode style as well)
// Time: O(N) | Space: O(N)
class Solution {
public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        stack<int> s;
        for (int i = 0; i < n; i++) s.push(i);

        while (s.size() > 1) {
            int a = s.top(); s.pop();
            int b = s.top(); s.pop();

            if (mat[a][b]) s.push(b); // a knows b -> a is not celebrity
            else s.push(a);           // a doesn't know b -> b is not celebrity
        }

        int cand = s.top();
        for (int i = 0; i < n; ++i) {
            if (i != cand && (mat[cand][i] || !mat[i][cand])) return -1;
        }

        return cand;
    }
};


// 2 pointer optimal (works on leetcode style as well)
// Time: O(N) | Space: O(1)
class Solution {
public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        int cand = 0;

        for (int i = 1; i < n; ++i) {
            if (mat[cand][i]) cand = i;
        }

        for (int i = 0; i < n; ++i) {
            if (i != cand && (mat[cand][i] || !mat[i][cand])) return -1;
        }

        return cand;
    }
};

// ------------------------------------------------------------------------------------------------------------------------------------ // 
// ------------------------------------------------------------------------------------------------------------------------------------ // 
