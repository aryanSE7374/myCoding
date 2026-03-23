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

#include<bits/stdc++.h>
using namespace std;

int LCS(string s1, string s2) {

        int m = s1.size() ;
        int n = s2.size() ;

        vector<int> prev (n+1 , 0) ;
        vector<int> curr (n+1 , 0) ;

        for ( int i=1 ; i<=m ; i++ ) { 
            for ( int j=1 ; j <=n ; j++ ) {
                if ( s1[i-1] == s2[j-1] ) curr[j] = 1 + prev[j-1] ;
                else curr[j] = max ( prev[j] , curr[j-1] ) ;
            }
            prev = curr ;
        }

        return prev[n] ;

    }


void SOLVE(){

    string s;
    cin >> s;

    int n = s.size();

    string s2 = "hello";

    int ans = LCS ( s , s2 );

    if ( ans == 5 ) cout << "YES";
    else cout << "NO";



    cout<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--){
        SOLVE();
    }
    return 0;
}