#include<bits/stdc++.h>
using namespace std;


// -------------------------------------------------------------------------------------------------------------------------- //
// -------------------------------------------------------------------------------------------------------------------------- //

/*

// NOTE : important point

When edges are unit weight:
Queue only needs node.
Distance array tracks steps.


When edges have weights:
Use priority_queue and store {dist, node}.

*/


// -------------------------------------------------------------------------------------------------------------------------- //
// -------------------------------------------------------------------------------------------------------------------------- //

// -------------------------------------------------------------------------------------------------------------------------- //

// TC : O(V × N) = O( 1e5 × N )
// SC: O(V) { V for dist and V for queue }

// -------------------------------------------------------------------------------------------------------------------------- //

// striver's simple shortest-path BFS approach (this version os clean and feels more natural)
// Queue stores nodes
// Steps is auxiliary info
// aligns with : BFS → process node → relax neighbors

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        
        const int INF = 1e9 ;
        const int mod = 1e5 ;
        
        if ( start == end ) return 0; // without this line some test acses gives WA
        
        queue<pair<int, int>> q;  // {node , steps}
        q.push({start, 0});
        
        vector<int> dist(1e5, INF);
        dist[start] = 0;
        
        while ( !q.empty() ) {
            auto[node, steps] = q.front();
            q.pop();
            
            for ( auto it : arr ) {
                int num = (it*node)%mod;
                if ( num == end ) return (steps+1) ;
                if (dist[num] > steps + 1) { // this check is mandatory to get rid of TLE
                    dist[num] = steps+1;
                    q.push({num, steps+1});
                }
            }
        }
        
        return -1;
        
    }
};

// -------------------------------------------------------------------------------------------------------------------------- //

// reversed queue storage version
// NOTE : Both versions are correct and There is no algorithmic difference.
// interview ques : Why distance first if you’re not using priority_queue?
// argument : if distnace first (seems closer to dijkstra) then why not priority_queue used
// hence this ordering gives no conceptual advantage
// insight : Not wrong — just slightly less conventional.

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        
        const int INF = 1e9 ;
        const int mod = 1e5 ;
        
        if ( start == end ) return 0; // without this line some test acses gives WA
        
        queue<pair<int, int>> q; // { steps , node }
        q.push({0, start});
        
        vector<int> dist(1e5, INF);
        dist[start] = 0;
        
        while ( !q.empty() ) {
            auto[ steps, node] = q.front();
            q.pop();
            
            for ( auto it : arr ) {
                int num = (it*node)%mod;
                if ( num == end ) return (steps+1) ;
                if (dist[num] > steps + 1) { // this check is mandatory to get rid of TLE
                    dist[num] = steps+1;
                    q.push({steps+1, num});
                }
            }
        }
        
        return -1;
        
    }
};

// -------------------------------------------------------------------------------------------------------------------------- //