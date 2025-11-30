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

void SOLVE(){

    int n,k,q;
    cin >> n >> k >> q;

    vector< tuple<int,int,int> > query;
    query.reserve(q);

    // range_c2[i] != k for all i
    vi c2_mexk(n , 0);

    f(i,0,q){

        int c,l,r;
        cin >> c >> l >> r;

        l--; r--;

        query.push_back({c,l,r});

        if(c == 2){
            for(int j=l ; j<=r ; j++)
                c2_mexk[j] = 1;   // k not allowed here
        }

    }

    vi res(n , k+1);

    // c1 -> min = k
    f(i,0,q){

        int c = get<0>(query[i]);
        int l = get<1>(query[i]);
        int r = get<2>(query[i]);

        if(c == 1){

            bool k_flag = false;

            for(int j=l ; j<=r ; j++){

                if(res[j] == k){
                    k_flag = true;
                    break;
                }

            }

            if(!k_flag){
                // assig k where c2_mexk = 0
                for(int j=l ; j<=r ; j++){
                    if(c2_mexk[j] == 0){
                        res[j] = k;
                        break;
                    }
                }
            }
        }
    }

    // c2 -> mex = k
    f(i,0,q){

        int c = get<0>(query[i]);
        int l = get<1>(query[i]);
        int r = get<2>(query[i]);

        if(c == 2){

            // used  = { 0 to k-1 }
            vi used(k , 0);

            for(int j=l ; j<=r ; j++){

                if(res[j] >= 0 && res[j] < k){
                    used[res[j]] = 1;
                }

            }

            int s = l;

            // fill i : used[i] == 0
            for(int i=0 ; i<k ; i++){

                if(used[i] == 0){

                    while(s <= r && res[s] <= k){
                        s++;
                    }

                    if(s <= r){
                        res[s] = i;
                        s++;
                    }
                }
            }

        }
    }

    // f(i,0,q){

    //     // input tuples 

    //     int c , l ,r;
    //     // cin >> c >> l >> r;

    //     // c = query[i][0];
    //     // l = query[i][1];
    //     // r = query[i][2];

    //     c = get<0>(query[i]);
    //     l = get<1>(query[i]);
    //     r = get<2>(query[i]);

    //     if (c == 1) {
    //         f(j,l-1,r){
    //             if(res[j] == INT_MIN || res[j] < k ){
    //                 res[j] = k;
    //             }
    //         }
    //     }
    //     else {
    //         f(j,l-1,r){
    //             if(res[j] == INT_MIN || res[j] <= k){
    //                 res[j] = k+1;
    //             }
    //         }
    //     }

    // }

    f(i,0,n){
        // if(res[i] == INT_MIN) res[i] = k+1;
        cout << res[i] << " ";
    }

    co_endl;

}

int main(){

    int t;
    cin>>t;
    while(t-->0){

        SOLVE();

    }

    return 0;
}