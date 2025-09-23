#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p, sz;
    DSU(int n) : p(n+1), sz(n+1,1) { iota(p.begin(), p.end(), 0); }
    int find(int x) { return p[x]==x ? x : p[x]=find(p[x]); }
    void unite(int a, int b) {
        a=find(a), b=find(b);
        if(a!=b) {
            if(sz[a]<sz[b]) swap(a,b);
            p[b]=a; sz[a]+=sz[b];
        }
    }
};

void solve() {
    int n,m; cin>>n>>m;
    vector<vector<int>> sets(n);
    vector<bool> seen(m+1,false);

    for(int i=0;i<n;i++){
        int l; cin>>l;
        sets[i].resize(l);
        for(int j=0;j<l;j++){ 
            cin>>sets[i][j]; 
            seen[sets[i][j]]=true; 
        }
    }

    for(int i=1;i<=m;i++) if(!seen[i]){ cout<<"NO\n"; return; }

    DSU dsu(m);
    for(auto &s:sets) for(int i=1;i<(int)s.size();i++) dsu.unite(s[0],s[i]);

    map<int,int> compSize;
    map<int,set<int>> compSets;
    for(int i=1;i<=m;i++) compSize[dsu.find(i)]++;
    for(int i=0;i<n;i++) if(!sets[i].empty()) compSets[dsu.find(sets[i][0])].insert(i);

    int two=0;
    for(auto &[r,sz]:compSize){
        int k=compSets[r].size();
        if(k>sz){ cout<<"YES\n"; return; }
        if(k==sz) two++;
    }
    cout<<(two>=2 ? "YES\n":"NO\n");
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
}