// Tarjan's Algorithm

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

/*
algorithm : 

perform dfs for traversal
during traversal - maintain : vis, inTime, lowTime
also keep track of the parent of the node

inTime : timer when the ndoe is traversed for the first time during dfs
lowTime : min time which a mode can reach from all his adjacent nodes (exluding its parent node)

// important test-case to debug : 

T
V E
E edges (u, v)

1
6 7
0 4
0 5
1 4
1 5
2 3
2 4
4 5

----------------------------         

        (2)--(3)
         |
         |
   (0)--(4)--(1)
    \    |    /
     \   |   /
      \_(5)_/     

----------------------------


*/

// implementation of tarjan's algorithm

int timer = 1;

void dfs (int u, int parent, vector<vector<int>>& adj, vector<int>& vis, vector<int>& inTime, vector<int>& lowTime, vector<vector<int>>& ans) {

    vis[u] = 1;
    inTime[u] = timer;
    lowTime[u] = timer;
    timer++;

    for ( auto v : adj[u] ) { // explore all the adjacent nodes
        if ( v == parent )  continue; // if it's a parent, then ignore
        if ( !vis[v] ) { // if the node not explored
            dfs(v, u, adj, vis, inTime, lowTime, ans); // explore the node recursively
            lowTime[u] = min(lowTime[u], lowTime[v]); // minimize the time for all the adjacent nodes
            if ( (inTime[u] < lowTime[v]) ) { // check if it's a bridge or not
                ans.push_back({u,v});
            }
        }        
        else{ // this is imprtant : if the adjacent node is already visisted and it's not a parent => minimize the minTime of node
            lowTime[u] = min(lowTime[u], lowTime[v]);
        }
    }


}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    
    vector<vector<int>> adj(v, vector<int>() );
    vector<vector<int>> ans;

    for ( auto& ed : edges ) {
        int u = ed[0], v = ed[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(v, 0);
    vector<int> inTime(v);
    vector<int> lowTime(v);

    dfs ( 0, 0, adj, vis, inTime, lowTime, ans );

    return ans;


}

void SOLVE(){

    int v, e;
    cin >> v >> e;
    vector<vector<int>> edges(e);

    f(i,0,e) {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
    }

    vector<vector<int>> bridges = findBridges(edges, v, e);

    cout << bridges.size() << "\n";

    sort(bridges.begin(), bridges.end());

    for(auto& b : bridges) {
        sort(b.begin(), b.end());
        cout << b[0] << " " << b[1] << "\n";
    }


    // cout<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        SOLVE();
    }
    return 0;
}