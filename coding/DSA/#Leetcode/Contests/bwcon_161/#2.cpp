
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int m, n;
    vector<vector<bool>> visited;
    
    long long dfs(vector<vector<int>>& grid, int i, int j) {
    if(i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || grid[i][j] == 0)
        return 0;

    visited[i][j] = true;
    long long sum = grid[i][j];

    sum += dfs(grid, i+1, j);
    sum += dfs(grid, i-1, j);
    sum += dfs(grid, i, j+1);
    sum += dfs(grid, i, j-1);

    return sum;
}
    
    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        
        int count = 0;
        
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] > 0 && !visited[i][j]) {
                    int sum = dfs(grid, i, j); // sum of island
                    if(sum % k == 0) count++;
                }
            }
        }
        
        return count;
    }
};