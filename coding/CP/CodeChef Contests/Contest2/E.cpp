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

    int n,k;

    cin >> n >> k;

    string S;
    cin >> S;

    vi ans(n);

    
    int j = k-1;
    
    if(S[j] == '0'){
        cout << -1 << "\n";
        return;
    }

    ans[0] = j;

    int i=1;
    int sc = 1;

    int l = (j-1+n)%n; 
    int r = (j+1)%n;

    while(i<n){

        int c = -1;

        // if(l<0) l = n-1;
        // if(r>=n) r = 0;
        // if(j<0) j = n-1;
        // if(j>=n) j = 0;

        // if( (i+1)%2 == 1 ){
        //     sc += (S[j]-'0');
        // }
        // else {
        //     sc -= (S[j]-'0');
        // }

        if( (i+1)%2 == 1 ) {
            if(S[l] == '1'){
                // j = l;
                // l--;
                c = l;
            }
            else if(S[r] == '1'){
                // j = r;
                // r++;
                c = r;
            }
            else{
                // j = l;
                // l--;
                c = l;
            }
        }
        else{
            if(S[l] == '0'){
                // j = l;
                // l--;
                c = l;
            }
            else if(S[r] == '0'){
                // j = r;
                // r++;
                c = r;
            }
            else{
                // j = l;
                // l--;
                c = l;
            }
        }

        if( (i+1)%2 == 1 ){
            sc += (S[c]-'0');
        }
        else {
            sc -= (S[c]-'0');
        }

        if(sc <= 0){
            cout << -1 << "\n";
            return;
        }

        ans[i] = c; // 0 based indexing

        if(c == l){
            l = (l-1+n)%n; 
        }
        else{
            r = (r+1)%n;
        }

        i++;

    }

    for( int idx : ans ){
        cout << idx+1 << " ";
    }

    co_endl;
    
}

int main(){

    int t;
    cin>>t;
    while(t-->0){

        SOLVE();

    }

    return 0;
}