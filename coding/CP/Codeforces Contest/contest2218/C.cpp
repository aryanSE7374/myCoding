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

    vi a(3*n);

    f(i,0,n){
        a[3*i + 2] = 3*n - 2*i;
        a[3*i + 1] = 3*n - 2*i - 1;
        a[3*i] = i+1;
    }

    f(i,0,3*n){
        cout << a[i] << " ";
    }

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