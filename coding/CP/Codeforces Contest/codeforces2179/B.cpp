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

    // greedy

    string s;
    cin >> s;

    int n = s.size();

    int count = 0;

    if(s[0] == 'u'){
        s[0] = 's';
        count++;
    }

    if(s[n-1] == 'u'){
        s[0] = 's';
        count++;
    }

    bool flag = false;
    for(int i=1 ; i<n-1 ; i++){

        if(s[i]=='u' && flag){
            s[i] = 's';
            count++;
            flag = false;
        }

        else if(s[i] == 's'){flag = false;}

        else flag = true;

    }

    cout << count ;

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