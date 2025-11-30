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

    f(i,0,q){

        // input tuples 

        int c , l ,r;
        cin >> c >> l >> r;

        if (c == 1) {
            f(j,l-1,r){
                if(res[j] == INT_MIN || res[j] < k ){
                    res[j] = k;
                }
            }
        }
        else {
            f(j,l-1,r){
                if(res[j] == INT_MIN || res[j] <= k){
                    res[j] = k+1;
                }
            }
        }

    }


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