#include<bits/stdc++.h>
using namespace std;

// my brute try 1

class Solution {
public:
    int m1;
    int n1;
    bool isValid ( int i, int j ){
        return ( (i>=0) && (i<m1) && (j>=0) && (j<n1) );
    }

    // vector<vector<vector<int>>> vis;
    vector<vector<vector<int>>> dp;
    // dp[i][j][cnt] = max energy seen at this state

    void dfs ( vector<string>& classroom, const int& maxE, int i, int j, int cnt, int steps, int currE, int& ans ) {

        if ( cnt == 0 ) {
            ans = min ( ans, steps );
            return;
        }

        if (dp[i][j][cnt] >= currE) return;
        dp[i][j][cnt] = currE;

        if ( currE < 0 ) { // not needed
            return;
        }
        // if ( steps > 20*20 ) return; // assumption : not needed anymore

        int di[] = {-1,0,1,0};
        int dj[] = {0,1,0,-1};

        for ( int k=0; k<4; k++ ) {

            int newi = i + di[k];
            int newj = j + dj[k];

            if ( isValid (newi, newj) && currE > 0 && classroom[newi][newj] != 'X' ) {

                if ( classroom[newi][newj] == 'L' ) {
                    classroom[newi][newj] = '.';
                    dfs ( classroom, maxE, newi, newj, cnt-1, steps+1, currE-1, ans);
                    classroom[newi][newj] = 'L'; // backtrack
                }

                else if ( classroom[newi][newj] == 'R' ) {
                    // int mask = n1*newi + newj;
                    // if ( !vis[newi][newj][mask] ) {
                    //     vis[newi][newj][mask] = 1;    
                    // }
                    dfs ( classroom, maxE, newi, newj, cnt, steps+1, maxE, ans);
                }

                else { // '.' or 'S'
                    dfs ( classroom, maxE, newi, newj, cnt, steps+1, currE-1, ans);
                }

            }

        }
        
    }

    int minMoves(vector<string>& classroom, int energy) {

        int m = classroom.size();
        int n = classroom[0].size();

        m1=m;
        n1=n;

        int istart, jstart;
        int litters = 0;

        for ( int i=0; i<m; i++ ) {
            for ( int j=0; j<n ; j++ ) {
                if ( classroom[i][j] == 'S' ) {
                    istart = i;
                    jstart = j;
                }
                if ( classroom[i][j] == 'L' ) litters++;
            }
        }

        // vector<vector<vector<int>>> vis(m, vector<vector<int>>(n, vector<int>(n*m))); // mask for litter : n*i + j
        // vis.assign(m, vector<vector<int>>(n, vector<int>(n*m, 0))); // mask for litter : n*i + j

        dp.assign(m, vector<vector<int>>(n, vector<int>(litters+1, -1)));

        if ( litters == 0 ) return 0;

        int ans = 1e9;
        dfs(classroom, energy, istart, jstart, litters, 0, energy, ans);
        return (ans == 1e9) ? -1 : ans;

    }
};


// ------------------------------------------------------------------------------------------------------------ //

// sol 1 : TLE

class Solution {
public:
    int minMoves(vector<string>& grid, int maxE) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> id(m, vector<int>(n, -1));
        int totalL = 0;

        int si, sj;

        // assign ids
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'S') {
                    si = i;
                    sj = j;
                }
                if (grid[i][j] == 'L') {
                    id[i][j] = totalL++;
                }
            }
        }

        // initial collected state
        vector<bool> startMask(totalL, false);

        // dp[i][j] -> map of collected state to max energy
        vector<vector<map<vector<bool>, int>>> dp(m, vector<map<vector<bool>, int>>(n));

        queue<tuple<int,int,vector<bool>,int>> q;
        q.push({si, sj, startMask, maxE});

        int steps = 0;

        int di[] = {-1,0,1,0};
        int dj[] = {0,1,0,-1};

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [i, j, collected, energy] = q.front();
                q.pop();

                // goal check
                // if (all_of(collected.begin(), collected.end(), [](bool x){ return x; })) {
                //     return steps;
                // }
                // alternative of above code block
                bool done = true;
                for (bool x : collected) {
                    if (!x) {
                        done = false;
                        break;
                    }
                }
                if (done) return steps;

                // pruning
                if (dp[i][j].count(collected) && dp[i][j][collected] >= energy) continue;
                dp[i][j][collected] = energy;

                for (int k = 0; k < 4; k++) {
                    int ni = i + di[k];
                    int nj = j + dj[k];

                    if (ni < 0 || nj < 0 || ni >= m || nj >= n) continue;
                    if (grid[ni][nj] == 'X') continue;

                    vector<bool> newCollected = collected;
                    int newEnergy = energy - 1;

                    // if (grid[ni][nj] == 'L') {
                    //     newCollected[id[ni][nj]] = true;
                    //     newEnergy--;
                    // }
                    // else if (grid[ni][nj] == 'R') {
                    //     newEnergy = maxE;
                    // }
                    // else {
                    //     newEnergy--;
                    // }

                    if (newEnergy < 0) continue;
                    if (newEnergy < 0) continue;

                    if (grid[ni][nj] == 'R') {
                        newEnergy = maxE;
                    }

                    if (grid[ni][nj] == 'L') {
                        newCollected[id[ni][nj]] = true;
                    }

                    q.push({ni, nj, newCollected, newEnergy});
                }
            }

            steps++;
        }

        return -1;
    }
};


// ------------------------------------------------------------------------------------------------------------ //

// optimal solution : 
/*
States ≈ m * n * 2^L
Transitions = 4

Time ≈ O(m * n * 2^L)
Space ≈ same
*/


class Solution {
public:
    int minMoves(vector<string>& grid, int maxE) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> id(m, vector<int>(n, -1));
        int totalL = 0;

        int si, sj;

        // assign ids to litters
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'S') {
                    si = i;
                    sj = j;
                }
                if (grid[i][j] == 'L') {
                    id[i][j] = totalL++;
                }
            }
        }

        int finalMask = (1 << totalL) - 1;

        // dp[i][j][mask] = max energy seen
        vector dp(m, vector(n, vector<int>(1 << totalL, -1)));

        queue<tuple<int,int,int,int>> q;
        q.push({si, sj, 0, maxE});

        int steps = 0;

        int di[] = {-1,0,1,0};
        int dj[] = {0,1,0,-1};

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [i, j, mask, energy] = q.front();
                q.pop();

                if (mask == finalMask) return steps;

                if (dp[i][j][mask] >= energy) continue;
                dp[i][j][mask] = energy;

                for (int k = 0; k < 4; k++) {
                    int ni = i + di[k];
                    int nj = j + dj[k];

                    if (ni < 0 || nj < 0 || ni >= m || nj >= n) continue;
                    if (grid[ni][nj] == 'X') continue;

                    int newMask = mask;
                    int newEnergy = energy - 1;

                    if (newEnergy < 0) continue;

                    if (grid[ni][nj] == 'R') {
                        newEnergy = maxE;
                    }

                    if (grid[ni][nj] == 'L') {
                        newMask |= (1 << id[ni][nj]);
                    }

                    // if (grid[ni][nj] == 'L') {
                    //     newMask |= (1 << id[ni][nj]);
                    //     newEnergy--;
                    // }
                    // else if (grid[ni][nj] == 'R') {
                    //     newEnergy = maxE;
                    // }
                    // else {
                    //     newEnergy--;
                    // }

                    q.push({ni, nj, newMask, newEnergy});
                }
            }

            steps++;
        }

        return -1;
    }
};