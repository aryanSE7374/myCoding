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

    int n ;
    string S;

    cin >> n ;
    cin >> S;

    int cntz = 0;
    int cnto = 0;

    int lastz;

    f(i,0,n){
        if ( S[i] == '1' ) cnto++;
        else {
            cntz++;
            lastz = i;
        }
    }

    if ( cntz < 1 || cnto < 1 ) {
        cout << "Bob\n";
        return ;
    }

    if ( is_sorted ( S.begin() , S.end() ) ) {
        cout << "Bob\n";
        return;
    }

    // int m = 0;

    int i = 0 , j = lastz ;

    vi seq ;

    while ( i < j ) {

        if ( S[i] == '1' && S[j] == '0' ) {

            S[i] = '0';
            S[j] = '1';

            seq.push_back(i);
            seq.push_back(j);

            i++;
            j--;

        }

        if ( S[j] == '1') {
            j--;
        }

        if ( S[i] == '0') {
            i++;
        }

    }

    sort ( seq.begin() , seq.end() ) ;

    int m = seq.size();

    cout << "Alice\n";

    cout << m ;
    co_endl;
    
    f(i,0,m){
        cout << seq[i] + 1 << " " ;
    }

    // int m = lastz + 1 ;

    // cout << m ;
    // co_endl;
    
    // f(i,1,m+1){
    //     cout << i << " " ;
    // }

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