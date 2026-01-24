/*
code by - Aryan Shrivastav
*/

/*
observations : 

*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define co_endl cout<<'\n'
#define f(i,a,n) for(int i=a ; i<n ; i++)

// int dist ( vector< vector<int> >& adj , int i ){
//     queue<int> q;
//     while(!q.empty()){

//         int u = q.front();

//         q.pop();

//         for(int v : adj[u]){
//             if(!isVisited[v]){

//                 isVisited[v] = true;

//                 distance[v] = distance[u] + 1;

//                 dist_freq[distance[v]]++;
//                 connected_freq[u]++;

//                 q.push(v);
//             }
//         }
//     }
// }

void SOLVE(){

    int n;
    cin >> n;
    vector< vector<int> > adj( n+1 ); 

    f(i,0,n-1){
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        // adj[u][0] = v;
        // adj[v][1] = u;
    }

    int ans = 0;

    vector<int> distance( n+1 , 0); // 1-based indexing , 0 => invalid distance
    
    // f(i,1,n){
    //     distance[i] = dist( adj , i );
    // }

    int maxDistVertex = 1; // group of distance d[i] having the max distance with max disconnected vertices


    // 1-based indexing
    vector<int> dist_freq( n+1 , 0); // freq of nodes at dist d[i]
    vector<int> connected_freq( n+1 , 0); // freq of connected vertices
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
                connected_freq[u]++;
                dist_freq[distance[v]]++;

                q.push(v);

            }
        }

    }

    /*
    ans = max (i=1 to n){ d[i] } + max ( 0 , [ rem - max (all grps having max dist ){count of disconnected components with group of d[i] } ] ) 
    rem = remaining after removing all the nodes of a particular distance group
    */

    f(i,1,n+1){
        ans = max ( ans , dist_freq[i]);
    }
    f(i,1,n+1){
        ans = max ( ans , 1 + connected_freq[i]) ;
    }

    cout << ans ;


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