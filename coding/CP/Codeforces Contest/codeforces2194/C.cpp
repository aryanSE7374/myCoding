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



// KMP Algo 

int informativity(string &s){

    int n = s.size();

    vector<int> lps( n , 0 );

    // Build LPS array
    for ( int i = 1 ; i < n ; i++ ) {

        int j = lps[i-1];

        while ( j > 0 && s[i] != s[j] ) {
            j = lps[j-1];
        }

        if ( s[i] == s[j] ) {
            j++;
        }

        lps[i] = j;

    }

    if ( ( n % (n - lps[n-1]) ) == 0){
        return (n - lps[n-1]) ;
    }
        

    return n;

}


// int fun ( string &s1 , ) {

// }

// bool check( vector<string>& V , vector<unordered_map<char,ll>>& freqs , int d ){
//     for ( int i=0 ; i<d ; i++ ) {
//         // check each group element 
//     }
// }

// bool check(vector<vector<int>>& freqs, int n, int d, string &ans){
bool check(vector<unordered_map<char,ll>>& freqs, int n, int d, string &ans){

    // ans.assign(n, '$');
    ans.resize(n);

    for ( int i = 0 ; i < d ; i++ ) {

        vi possible(26,1);

        // intersecting columns
        for ( int j = i ; j < n ; j = j + d ) {

            for(int c = 0; c < 26; c++){
                // possible[c] = possible[c] & freqs[j]['a'+c];
                possible[c] = possible[c] & ( freqs[j].count('a'+c)>0 );
            }

            // for(int c = 0; c < 26; c++){
            //     possible[c] = possible[c] & freqs[j][c];
            // }
        }

        char c = '$';
        for(int j = 0; j < 26; j++){
            if(possible[j]){
                c = 'a'+j;
                break;
            }
        }

        if( c == '$') return false;

        for(int j = i; j < n; j += d){
            // ans[j] = char('a' + c);
            ans[j] = c;
        }

    }

    return true;
}

void SOLVE(){

    ll n , k;

    cin >> n >> k;

    vector<string> V(k);

    // vector<unordered_map<char,ll>> freqs(k); // index -> { char , freq }
    vector<unordered_map<char,ll>> freqs(n);

    f(i,0,k){
        cin >> V[i] ;
        // unordered_map<char,ll> mpp;
        // f(j,0,n){
        //     mpp[V[i][j]]++;
        // }
        // freqs[i]=mpp;
        f(j,0,n){
            freqs[j][V[i][j]] = 1;
        }
    }



    // check divisors of n only

    vector<int> divisors;

    for (int i = 1 ; i*i <= n ; i++ ) {
        if ( (n%i) == 0 ){
            divisors.push_back(i);
            if (i != n/i ) divisors.push_back(n/i);
        }
    }

    sort(divisors.begin() , divisors.end() );

    string ans('#',n);
    // for ( int i=1 ; i*i <= n ; i++ ) {
    //     if ( n%i == 0 ) {
    //         if ( check( freqs , n , i , ans ) ){
    //             cout << ans;
    //             co_endl;
    //             return;
    //         }
    //     }
    // }

    for ( int d : divisors ) {
        if ( check( freqs , n , d , ans ) ){
            cout << ans;
            co_endl;
            return;
        }
    }

    // string ans = fun();

    cout << ans;

    co_endl;

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){

        SOLVE();

    }

    return 0;
}