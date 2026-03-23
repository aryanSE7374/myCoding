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

    int n , x , y;

    cin >> n >> x >> y ;

    vi p(n);
    const int INF = 1e9;

    int M0 = INF;
    int M1 = INF;
    int M2 = INF;

    f(i,0,n) {
        cin >> p[i];
        if ( i<x ) {
            M0 = min ( M0 , p[i] );
        }
        else if ( i<y ) {
            M1 = min ( M1 , p[i] );
        }
        else {
            M2 = min ( M2 , p[i] );
        }
    }

    vi temp(y-x);
    int minIdx = x;

    f(i,x,y){
        if ( p[i] == M1 ) {
            minIdx = i;
            break;
        }
    }

    int j=0;
    f(i,minIdx,y){
        temp[j] = p[i];
        j++;
    }

    f(i,x,minIdx){
        temp[j] = p[i];
        j++;
    }

    // temp is cyclic sorted mid

    int i=x-1;

    vi aux;

    // while ( i>=0 && p[i]>M1 ) {
    //     aux.push_back(p[i]);
    //     i--;
    // }

    int gIdx = -1;
    f(k,0,x) {
        if ( p[k] > M1 ) {
            gIdx = k;
            break;
        }
    }

    if ( gIdx != -1 ) {
        while ( i >= gIdx ) {
            aux.push_back(p[i]);
            i--;
        }
    }

    // fill 0 to i in ans

    vi ans(n);

    int ptr = 0;

    f(k,0,i+1){
        ans[ptr] = p[k];
        ptr++;
    }

    if ( aux.size() == 0 ) { // aux section , then mid , then right

        i=y;
        while( i<n && p[i]<M1 ) {
            aux.push_back(p[i]);
            i++;
        }

        // aux in order
        // reverse(aux.begin(),aux.end());
        for ( int num : aux ) {
            ans[ptr] = num;
            ptr++;
        }

        for ( int num : temp ) {
            ans[ptr] = num;
            ptr++;
        }

        // for ( k=i , )
        f(k,i,n){
            ans[ptr] = p[k];
            ptr++;
        }

    }
    else{ // mid section , then aux , then right

        for ( int num : temp ) {
            ans[ptr] = num;
            ptr++;
        }

        // aux in rev order
        reverse(aux.begin(),aux.end());
        for ( int num : aux ) {
            ans[ptr] = num;
            ptr++;
        }

        f(k,y,n){
            ans[ptr] = p[k];
            ptr++;
        }

    }

    f(i,0,n) {
        cout << ans[i] << " ";
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