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
    cin >> n;
    vi a(n);
    f(i,0,n){
        cin >>a[i];
    }

    int l = -1 ;
    int r = n ;
    f(i,0,n){
        if ( a[i] == 0 ){
            l = i;
            break;
        }
    }

    if ( l == -1 ) { 
        cout << "Alice\n";
        return;
    }

    for(int i=n-1 ; i>= 0 ; i--){
        if ( a[i] == 0 ){
            r = i;
            break;
        }
    }

    if ( l== r ) { 
        cout << "Alice\n";
        return;
    }

    if ( l>0 || r<n-1 ){
        cout << "Alice\n";
        return;
    }

    else{ 
        cout << "Bob\n";
        return;
    }

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