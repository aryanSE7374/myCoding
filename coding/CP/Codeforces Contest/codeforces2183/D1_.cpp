/*
code by - Aryan Shrivastav
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define co_endl cout<<'\n'
#define f(i,a,n) for(int i=a ; i<n ; i++)

void SOLVE(){

    int n;
    cin >> n; // FIXED: Read n before using it!

    // FIXED: Use standard adjacency list (dynamic size)
    vector< vector<int> > adj( n+1 ); 

    f(i,0,n-1){
        int u , v;
        cin >> u >> v;
        // FIXED: Store the edges properly for an undirected tree
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 0;

    // 1-based indexing
    vector<int> distance( n+1 , 0); 
    vector<int> dist_freq( n+1 , 0); // freq of nodes at dist d[i]
    vector<int> connected_freq( n+1 , 0); // freq of children for node i
    vector<bool> isVisited( n+1 , false );

    // bfs
    queue<int> q;

    q.push(1); // root

    isVisited[1] = true ;
    distance[1] = 1 ; 
    dist_freq[1]++ ;

    while( !q.empty() ) {

        int u = q.front();
        q.pop();

        for( int v : adj[u] ){

            if( !isVisited[v] ){
                isVisited[v] = true;

                distance[v] = 1 + distance[u] ;
                
                // u is the parent, v is the child.
                // We increment connected_freq for u (counting its children)
                connected_freq[u]++; 
                dist_freq[distance[v]]++;

                q.push(v);
            }
        }
    }

    // Constraint 1: Max nodes at the same depth
    f(i,1,n+1){
        ans = max ( ans , dist_freq[i]);
    }

    // Constraint 2: Star graph constraint (Parent + all children form a conflict set)
    // You can pick at most 1 node from {Parent, Child1, Child2...}
    f(i,1,n+1){
        ans = max ( ans , 1 + connected_freq[i]) ;
    }

    cout << ans;
    co_endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t-->0){
        SOLVE();
    }

    return 0;
}