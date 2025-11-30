/*
code by - Aryan Shrivastav
*/

/*
Minimal fixes:
1) Sort queries by (r, l) → ensures smaller segments processed earlier.
   This prevents c1 from blocking positions needed for c2.

2) No change in your logic of processing c1 then c2.
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define co_endl cout<<'\n'
#define f(i,a,n) for(int i=a ; i<n ; i++)

void SOLVE(){

    ll n,k,q;
    cin >> n >> k >> q;

    vector< tuple<ll,ll,ll> > query;
    query.reserve(q);

    // Masks
    vll c2_mexk(n , 0);    // for c2: k not allowed
    vll c2_mexk2(n , 0);   // for c1: 0..k-1 not allowed

    f(i,0,q){

        ll c,l,r;
        cin >> c >> l >> r;
        l--; r--;

        query.push_back({c,l,r});

        if(c == 2){
            for(ll j=l ; j<=r ; j++){
                c2_mexk[j] = 1;
            }
        }
        else{
            for(ll j=l ; j<=r ; j++){
                c2_mexk2[j] = 1;
            }
        }
    }

    vll res(n , k+1);

    // -------------------------------------------------------
    // 🔧 FIX: sort queries so tighter intervals are processed first
    // -------------------------------------------------------
    sort(query.begin(), query.end(),
        [](auto &A, auto &B){
            if(get<2>(A) != get<2>(B))
                return get<2>(A) < get<2>(B);   // sort by r
            return get<1>(A) < get<1>(B);       // then by l
        }
    );

    // ------------------------------------------
    // PHASE 1: handle c=1 → min = k
    // ------------------------------------------
    for(auto &qv : query){

        ll c = get<0>(qv);
        ll l = get<1>(qv);
        ll r = get<2>(qv);

        if(c == 1){

            bool k_flag = false;
            for(ll j=l ; j<=r ; j++){
                if(res[j] == k){
                    k_flag = true;
                    break;
                }
            }

            if(!k_flag){
                // place k at a position allowed for k
                for(ll j=l ; j<=r ; j++){
                    if(c2_mexk[j] == 0){ 
                        res[j] = k;
                        break;
                    }
                }
            }
        }
    }

    // ------------------------------------------
    // PHASE 2: handle c=2 → MEX = k
    // ------------------------------------------
    for(auto &qv : query){

        ll c = get<0>(qv);
        ll l = get<1>(qv);
        ll r = get<2>(qv);

        if(c == 2){

            vll used(k , 0);

            for(ll j=l ; j<=r ; j++){
                if(res[j] >= 0 && res[j] < k){
                    used[res[j]] = 1;
                }
            }

            ll s = l;

            for(ll need = 0 ; need < k ; need++){
                if(used[need] == 0){

                    // find a clean spot for 0..k-1
                    while(s <= r){
                        if(c2_mexk2[s] || res[s] != k+1){
                            s++;
                        }
                        else break;
                    }

                    if(s <= r){
                        res[s] = need;
                        s++;
                    }
                }
            }
        }
    }

    f(i,0,n){
        cout << res[i] << " ";
    }
    co_endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t-->0){
        SOLVE();
    }

    return 0;
}