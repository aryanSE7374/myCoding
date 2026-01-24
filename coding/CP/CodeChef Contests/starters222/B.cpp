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
    cin >> n ;
    vi a(n);

    unordered_map<int , int > freq;
    int maxi = 0;
    int minClr = INT_MAX;

    f(i,0,n) {

        cin >> a[i];
        freq[a[i]]++;

        if ( freq[a[i]] == maxi ) {
            if ( minClr > a[i] ) {
                minClr = a[i] ;
            }
        }

        else if ( freq[a[i]] > maxi ) {
            maxi = freq[a[i]] ;
            minClr = a[i] ;
        }

    }

    cout << minClr ;

    co_endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t-->0){

        SOLVE();

    }

    return 0;
}