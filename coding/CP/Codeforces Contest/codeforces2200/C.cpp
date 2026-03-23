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

    bool ans = true;

    f(i,1,n){
        if ( s[i-1] == s[i] ) {
            s[i-1] = '*';
            s[i] = '*' ;
            i++;
        }
    }

    bool flag = true;
    // int i=0;
    // int j=1;

    bool updated = false;

    // while ( (flag) && (i<n-1) && (j<n) ) {
    while ( (flag) ) {
        // if ( s[i] == s[j] )
        flag = false;
        updated = false;

        // while ( i<n && s[i] == '*' ) {
        //     i++;
        //     j=i+1;
        // }

        // while ( j<n && s[j]=='*' ) {
        //     j++;
        // }

        // if ( j<n && (s[i] == s[j]) ) {
        //     s[i] = '*';
        //     s[j] = '*';
        //     flag = true;
        //     updated = true;
        //     i=j+1;
        //     j=i+1;
        // }

        
        // else if ( j<n ) {
        //     i=j;
        //     j=i+1;
        //     flag = true;
        //     updated = true;
        // }
        
        // else {
        //     i=0;
        //     j=1;
        //     flag = true;
        //     if ( !updated ) break;

        // }

        int i=0;
        // int j=1;

        while ( i<n ) {

            while ( i<n && s[i] == '*' ) {
                i++;
            }
            if (i >= n) break;

            int j = i + 1;
            while ( j<n && s[j]=='*' ) {
                j++;
            }

            if (j < n && s[i] == s[j]) {
                s[i] = '*';
                s[j] = '*';
                flag = true;
                i = j+1;
            } 
            else{
                i=j;
            }

        }

    }

    f(i,0,n){
        if ( s[i] != '*' ) {
            ans = false;
            break;
        }
    }

    if ( ans ) cout << "YES";
    else cout << "NO";



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