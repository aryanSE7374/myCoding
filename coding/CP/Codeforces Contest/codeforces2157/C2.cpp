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

    vector<int> res (n , k+1);


    vector< tuple< int,int,int > > query; 
    query.reserve(q);

    f(i,0,q){

        int c,l,r;
        cin >> c >> l >> r;
        l--; r--;
        query.push_back({c,l,r});

    }

    // c1

    f(i,0,q){

        int c , l , r;
        c = get<0>(query[i]);
        l = get<1>(query[i]);
        r = get<2>(query[i]);

        if(c == 1){
            
            res[l] = k;
        }
    }
    // c2

    f(i,0,q){

        int c , l , r;

        c = get<0>(query[i]);
        l = get<1>(query[i]);
        r = get<2>(query[i]);

        if(c == 2){

            // int s = max( l , (r - k + 1) );
            int s = r - k + 1;
            
            for(int j = 0; j < k; j++){
                res[s + j] = j;
            }

            for(int j = l; j <= r; j++){

                if(res[j] == k){
                    res[j]++;
                    // res[j] = k+1;
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