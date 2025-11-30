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

    int n;
    cin>>n;

    vector<vector<int>> vec(n , vector<int>(n));

    int maxCost = INT_MIN;

    f(i,0,n){
        f(j,0,n){
            vec[i][j] = n*i + (j+1);
            // cout << vec[i][j] << " ";
        }
        // co_endl;
    }

    f(i,0,n){
        int cost = 0;
        f(j,0,n){
            int up = (i>0) ? vec[i-1][j] : 0;
            int down = (i<n-1) ? vec[i+1][j] : 0;
            int left = (j>0) ? vec[i][j-1] : 0;
            int right = (j<n-1) ? vec[i][j+1] : 0;

            cost =  ( vec[i][j] + up + down + left + right ) ;

            maxCost = max(maxCost , cost);

        }
    }

    cout << maxCost;

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