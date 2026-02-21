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

    int n;
    cin >> n;

    string s;
    cin >> s;

    int cnt0 = 0 , cnt1 = 0;
    f(i,0,n){
        if ( s[i] == '0' ) cnt0++;
        else cnt1++;
    }

    if ( cnt1 == 0 ) {
        cout << 0 << "\n";
        return ;
    }
    
    if ( (cnt0 == 1) && ( n > 1 ) ) {
        int idx = 0;
        f(i,0,n) {
            if ( s[i] == '0' ) {
                idx = i;
                break;
            }
        }
        cout << 1 << "\n";
        cout << idx+1 <<"\n";
        return ;
    }
    
    if ( (cnt1%2) == 0 ) {
        cout << cnt1 << "\n";
        f(i,0,n){
            if ( s[i] == '1' ) cout << i+1 << " ";
        }
        cout << "\n";
        return;
    }

    if ( ( (cnt1%2) == 1 ) && ( (cnt0%2) == 1 ) ) {
        // cout << "number of ones odd\n";
        // print all zeros indices
        cout << cnt0 << "\n";
        f(i,0,n){
            if ( s[i] == '0' ) cout << i+1 << " ";
        }
        cout << "\n";
        return;
    }

    if ( (cnt1%2) == 1 ) {
        // cout << "number of ones odd\n";
        cout << -1 << "\n";
        return;
    }


    cout << "-1"; 


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


/*

3
100


*/ 