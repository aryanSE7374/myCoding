// wrong


#include <bits/stdc++.h>
using namespace std;

#define f(i,a,b) for(int i=a;i<b;i++)
#define ll long long

void SOLVE() {
    int n,k,q;
    cin >> n >> k >> q;

    vector<pair<int,int>> c1, c2;
    c1.reserve(q);
    c2.reserve(q);

    f(i,0,q){
        int c,l,r;
        cin>>c>>l>>r;
        l--, r--;
        if(c==1) c1.push_back({l,r});
        else      c2.push_back({l,r});
    }

    vector<int> a(n, k+1);

    // ---------- TYPE 1: ensure min = k ----------
    for(auto &p : c1){
        int l=p.first, r=p.second;
        bool has_k=false;
        f(i,l,r+1) if(a[i]==k) has_k=true;
        if(!has_k) a[l]=k;   // place k at start
    }

    // ---------- TYPE 2: enforce MEX = k ----------
    for(auto &p : c2){
        int l=p.first, r=p.second;

        vector<int> used(k,0);
        f(i,l,r+1){
            if(a[i]>=0 && a[i]<k) used[a[i]]=1;
        }

        int pos=l;
        f(v,0,k){
            if(!used[v]){
                while(pos<=r && a[pos]<k) pos++;
                a[pos]=v;
                pos++;
            }
        }

        f(i,l,r+1){
            if(a[i]==k) a[i]=k+1;
        }
    }

    f(i,0,n) cout<<a[i]<<" ";
    cout<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--) SOLVE();
}