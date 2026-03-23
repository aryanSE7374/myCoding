/*
code by - Aryan Shrivastav
*/

/*
observations : 

*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
#define pii pair<int,int>
#define pll pair<long long,long long>
#define f(i,a,n) for(int i=a ; i<n ; i++)


void SOLVE(){

    vector<vector<char>> a(8,vector<char>(8));
    f(i,0,8){
        f(j,0,8){
            cin >> a[i][j];
        }
    }

    f(i,0,8){

        int j = 0;

        while ( j<8 ) {


            if(a[i][j] != 'R')  break;
            j++;
        }

        if ( j == 8 ) {
            cout << "R\n";
            return;
        }

    }

    cout << "B";

    cout<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        SOLVE();
    }
    return 0;
}