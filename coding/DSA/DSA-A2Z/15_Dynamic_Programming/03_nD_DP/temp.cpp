#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<pair<int,int>> directions1 = {{-1,-1}, {-1,1}, {-1,0}};

    bool is_possible(vector<string>& grid, int x, int y, int n) {
        
        for (auto dir : directions1) {
            int nx = x + dir.first;
            int ny = y + dir.second;

            while (nx >= 0 && ny >= 0 && ny < n) {
                if (grid[nx][ny] == 'Q')
                    return false;
                nx += dir.first;
                ny += dir.second;
            }
        }
        return true;
    }

    void generate(vector<string>& grid, vector<vector<string>>& ans, int n, int x) {
        if (x == n) {
            ans.push_back(grid);
            return;   
        }

        for (int j = 0; j < n; j++) {
            if (is_possible(grid, x, j, n)) {
                grid[x][j] = 'Q';
                generate(grid, ans, n, x + 1);
                grid[x][j] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> grid(n, string(n, '.'));
        vector<vector<string>> ans;
        generate(grid, ans, n, 0);
        return ans; 
    }
};




class Solution {
public:
    vector<pair<int,int>> directions1 = {{-1,-1}, {-1,1}, {-1,0}};

    bool is_possible(vector<string>& grid, int x, int y, int n) {
        if (x < 0 || y < 0 || y >= n) return true;

        if (grid[x][y] == 'Q') return false;

        for (auto dir : directions1) {
            int nx = x + dir.first;
            int ny = y + dir.second;

            if (!is_possible(grid, nx, ny, n))
                return false;
        }
        return true;
    }

    void generate(vector<string>& grid, vector<vector<string>>& ans, int n, int x) {
        if (x == n) {
            ans.push_back(grid);
            return;   
        }

        for (int j = 0; j < n; j++) {
            if (is_possible(grid, x, j, n)) {
                grid[x][j] = 'Q';
                generate(grid, ans, n, x + 1);
                grid[x][j] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> grid(n, string(n, '.'));
        vector<vector<string>> ans;
        generate(grid, ans, n, 0);
        return ans;
    }
};



class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxLen = 0;
        int l=0,r=0,zeroes=0;

        while(r<n){
            if(nums[r]==0){
                zeroes++;
            }
            if(zeroes>k){
                if(nums[l]==0){zeroes--;}
                l++;
            }
            if(zeroes<=k){
                maxLen=max(maxLen,r-l+1);
            }
            r++;
        }
        return maxLen;
    }
};


class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int n = nums.size();     // size of array
        int ans = 0;             // maintains the final answer (max window length)

        int tail = 0;            // left pointer (start of window)
        int head = -1;           // right pointer (end of window), starts before array
        int cntzero = 0;         // number of zeroes in current window

        // for every start position (tail)
        while (tail < n) {

            // expand the window as much as possible while it's valid
            while (head + 1 < n && (nums[head + 1] == 1 || cntzero < k)) {
                head++;
                if (nums[head] == 0)
                    cntzero++;
            }

            // update the answer for current start
            ans = max(ans, head - tail + 1);

            // move start one step forward
            if (tail > head) {
                // empty window case
                tail++;
                head = tail - 1;
            } else {
                // shrink window from left
                if (nums[tail] == 0)
                    cntzero--;
                tail++;
            }
        }

        return ans;
    }
};