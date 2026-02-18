#include<bits/stdc++.h>
using namespace std;

// try 1 : ovecomplicated the problem

class Solution {
  public:
  
    vector<int> topoSort(int V, vector<vector<int>>& adj , vector<int>& inDegree) {

        queue<int> q;
        
        for ( int i=0 ; i<V ; i++ ) {
            if ( inDegree[i] == 0 ) {
                q.push(i);
            }
        }
        
        vector<int> ans;
        
        while ( !q.empty()) {
            
            int u = q.front();
            q.pop();
            ans.push_back(u);
            
            for ( int v : adj[u] ) {
                inDegree[v]--;
                if ( inDegree[v] == 0 ) {
                    q.push(v);
                }
            }
        }
        
        return ans;
        
    }
    
    // over compilcated recursive calls
    bool f ( int l , int r , int idx , vector<string> st , vector<string> &S ) {
        // len string max = 100 
        if ( idx > 100 ) return true;
        string temp = "";
        
        vector<pair<int,int>> ranges;
        vector<int> vis(26,0);
        for ( int j = l ; j <= r ; j++ ) {
            
            int start = j , end = j;
            if ( S[j].size() > idx ) temp += S[j][idx];
            else continue;
            
            vis[S[j][idx]-'a'] = 1;
            j++;
            
            while( j < r && S[j][idx] == S[j-1][idx] ) {
                end = j;
                j++;
            }
            
            if ( j<r && vis[S[j][idx]] == 1 ) return false;
            j--;
            
            ranges.push_back( {start , end} ) ;
            
        }
        
        for ( auto it : ranges ) {
            if ( !f ( it.first , it.second , idx+1 , st , S ) ) return false;
        }
        
        st.push_back(temp);
        
        return true;
    }
    
    
    string findOrder(vector<string> &words) {
        
        int n = words.size();
        // set<pair<int,int>> edges;
        vector<string> edges;
        
        // rec call
        bool flag = f ( 0 , words.size()-1 , 0 , edges , words ) ;
        
        vector<vector<int>> adj;
        
        vector<int> inDegree(26,0);
        
        for (string str : edges ) {
            int sz = str.size();
            for ( int i=0 ; i<(sz-1) ; i++ ) {
                int u = str[i]-'a' , v = str[i+1]-'a';
                adj[u].push_back(v);
                inDegree[v]++;
            } 
        }
        
        int V = adj.size();
        vector<int> topo = topoSort(V , adj , inDegree );
        if ( topo.size() == V ) {
            string res('*',V);
            for ( int i=0 ; i<V ; i++) {
                res[i] = topo[i];
                return res;
            }
        }
        return "";
        

        
        
    }
};


/*
// custom testcases : 
baa baa bac abcd abca abca cab cad
baa baa bac abda abcc abcc cab cad
baa baa bac abca abdd abcc cab cad
*/

// ------------------------------------------------------------------------------------------------------------------------------------ //

// fixed code by GPT

class Solution {
public:
    
    vector<int> topoSort(vector<vector<int>>& adj, vector<int>& inDegree, vector<int>& present) {
        
        queue<int> q;
        
        // Push only present characters with indegree 0
        for (int i = 0; i < 26; i++) {
            if (present[i] && inDegree[i] == 0) {
                q.push(i);
            }
        }
        
        vector<int> ans;
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            ans.push_back(u);
            
            for (int v : adj[u]) {
                inDegree[v]--;
                if (inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        
        return ans;
    }
    
    string findOrder(vector<string> &words) {
        
        int N = words.size();
        
        vector<vector<int>> adj(26);
        vector<int> inDegree(26, 0);
        
        // Track which characters actually appear
        vector<int> present(26, 0);
        for (auto &w : words) {
            for (char c : w) {
                present[c - 'a'] = 1;
            }
        }
        
        // set to avoid duplicate edges
        set<pair<int,int>> edges;
        
        for ( int i = 0 ; i < N-1 ; i++ ) {
            
            string s1 = words[i];
            string s2 = words[i+1];
            
            int len = min(s1.size(), s2.size());
            bool flag = false;
            
            for (int p = 0; p < len; p++) {
                if (s1[p] != s2[p]) {
                    int u = s1[p] - 'a';
                    int v = s2[p] - 'a';
                    
                    edges.insert({u, v});
                    flag = true;
                    break;
                }
            }
            
            // Prefix invalid case
            if ( !flag && s1.size() > s2.size() ) return "";
            
        }
        
        for (auto &[u,v] : edges) {
            adj[u].push_back(v);
            inDegree[v]++;
        }
        
        // count actual number of unique characters
        int total = 0;
        for (int i = 0; i < 26; i++) {
            if (present[i]) total++;
        }
        
        vector<int> topo = topoSort(adj, inDegree, present);
        
        // cycle check
        if (topo.size() != total)
            return "";
        
        string ans = "";
        
        for (int node : topo) {
            ans += (node + 'a');
        }
        
        return ans;
    }
};

/*
// custom testcases : 
baa baa bac abcd abca abca cab cad
baa baa bac abda abcc abcc cab cad
baa baa bac abca abdd abcc cab cad
*/