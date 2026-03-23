#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
#define pii pair<int,int>
#define pll pair<long long,long long>
#define f(i,a,n) for(int i=a ; i<n ; i++)


// code360 : https://www.naukri.com/code360/problems/number-of-islands-ii_1266048


class DSU {

public:
    vector<int> rank, parent, size;

    DSU(int n){

        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1,1);

        for ( int i=0 ; i<=n ; i++ ) {
            parent[i] = i;
            // size[i] = 1;
        }

    }

    int findUltimateParent (int node) {
        if ( node == parent[node] ) return node;
        return parent[node] = findUltimateParent( parent[node] );
    }

    void unionByRank( int u, int v ) {
        int ult_Pu = findUltimateParent(u);
        int ult_Pv = findUltimateParent(v);

        if ( ult_Pu == ult_Pv ) return;
        
        if ( rank[ult_Pu] < rank[ult_Pv] ) {
            parent[ult_Pu] = ult_Pv;
        }

        else if ( rank[ult_Pv] < rank[ult_Pu] ) {
            parent[ult_Pv] = ult_Pu;
        }

        else{
            parent[ult_Pv] = ult_Pu;
            rank[ult_Pu]++;
        }
    }

    void unionBySize( int u, int v ){ 
        int ult_Pu = findUltimateParent(u);
        int ult_Pv = findUltimateParent(v);

        if ( ult_Pu == ult_Pv ) return;
        
        if ( size[ult_Pu] < size[ult_Pv] ) {
            parent[ult_Pu] = ult_Pv;
            size[ult_Pv] += size[ult_Pu];
        }

        else{
            parent[ult_Pv] = ult_Pu;
            size[ult_Pu] += size[ult_Pv];
        }
    }

};

// -------------------------------------------------------------------------------- //

// TUF+ : https://takeuforward.org/plus/dsa/problems/number-of-islands-ii

// my brute force try - correct but TC : O ( N * M * Q ) very high


class Solution1{
public:
vector<int> numOfIslands(int n, int m, vector<vector<int>> &q){

        int sz = q.size();
        int setSize = n*m;

        DSU djs(setSize);
        vector<int> ans(sz);
        // i,j -> m*i + j

        vector<vector<int>> grid( n, vector<int>(m,0) );

        int di[] = {-1, 0, 1 , 0};
        int dj[] = {0, 1 , 0, -1};

        int prevCnt = 0;

        for ( int p=0 ; p<sz ; p++ ) {
            int i = q[p][0] , j = q[p][1];
            if ( grid[i][j] == 0 ) {
                grid[i][j] = 1;
                for ( int k=0 ; k<4 ; k++ ) {
                    int r = i + di[k];
                    int c = j + dj[k];
                    if ( 
                        0 <= r && r<n && 0<=c && c<m && grid[r][c] == 1 
                    ) {
                        djs.unionBySize( (m*i + j) , (m*r + c) );
                    }
                }
                // count connected
                int cnt = 0;
                for ( int u=0 ; u<setSize ; u++ ) {
                    if ( (u == djs.parent[u]) && (grid[u/m][u%m] == 1) ) cnt++;
                }
                ans[p] = cnt;
                prevCnt = cnt;
            }
            else{
                ans[p] = prevCnt;
            }

        }

        return ans;

    }
};


// -------------------------------------------------------------------------------- //

// my optimal try - correct
// Time:  O(Q * 4 * α(N*M))
// Space: O(N*M)

class Solution2{
public:
vector<int> numOfIslands(int n, int m, vector<vector<int>> &q){

        int sz = q.size(); // queries size
        int setSize = n*m;

        DSU djs(setSize);
        vector<int> ans(sz);
        // i,j -> m*i + j

        vector<vector<int>> grid( n, vector<int>(m,0) ); // visited

        int di[] = {-1, 0, 1 , 0};
        int dj[] = {0, 1 , 0, -1};

        int cnt = 0;

        for ( int p=0 ; p<sz ; p++ ) {
            int i = q[p][0] , j = q[p][1];
            if ( grid[i][j] == 0 ) { // if not visited
                grid[i][j] = 1; // mark as visited
                cnt++;
                int node = (m*i + j);
                for ( int k=0 ; k<4 ; k++ ) {
                    int r = i + di[k];
                    int c = j + dj[k];
                    if ( (0<=r) && (r<n) && (0<=c) && (c<m) && (grid[r][c] == 1) ) {
                        int neighbour = (m*r + c);
                        if (djs.findUltimateParent(node) != djs.findUltimateParent(neighbour)) {
                            djs.unionBySize( node, neighbour );
                            cnt--;
                        }
                    }
                }
            }
            ans[p] = cnt;
        }

        return ans;

    }
};


// -------------------------------------------------------------------------------- //

// striver's optimal code
// Time:  O(Q * α(N*M))
// Space: O(N*M)
class Solution{
public:

    bool isValid(int r, int c, int n, int m){
        return (r >= 0 && r < n && c >= 0 && c < m);
    }

    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators){

        DSU ds(n * m);

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int cnt = 0;
        vector<int> ans;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        for(auto it : operators){

            int row = it[0];
            int col = it[1];

            if(vis[row][col] == 1){
                ans.push_back(cnt);
                continue;
            }

            vis[row][col] = 1;
            cnt++;

            for(int ind = 0; ind < 4; ind++){

                int adjr = row + dr[ind];
                int adjc = col + dc[ind];

                if(isValid(adjr, adjc, n, m)){

                    if(vis[adjr][adjc] == 1){

                        int nodeNo = row * m + col;
                        int adjNodeNo = adjr * m + adjc;

                        if(ds.findUltimateParent(nodeNo) != ds.findUltimateParent(adjNodeNo)){

                            cnt--;
                            ds.unionBySize(nodeNo, adjNodeNo);
                        }
                    }
                }
            }

            ans.push_back(cnt);
        }

        return ans;
    }
};

// -------------------------------------------------------------------------------- //

vector<int> numOfIslandsII(int n, int m, vector<vector<int>> &q){
    // participants implement this
    vector<int> ans(q.size(),0);
    return ans;
}

// -------------------------------------------------------------------------------- //

void SOLVE() {

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> q(k, vector<int>(2));

    for(int i = 0; i < k; i++){
        cin >> q[i][0] >> q[i][1];
    }

    Solution obj;
    vector<int> ans = obj.numOfIslands(n, m, q);

    for(int x : ans) cout << x << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    while(t--){
        SOLVE();
    }

    return 0;
}