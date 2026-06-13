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

    vi a(n);

    vi a2;
    vi a3;
    vi a6;
    vi temp;
    
    f(i,0,n){
        cin >> a[i];
        if (a[i]%6 == 0 ) {
            a6.push_back(a[i]);
        }
        else if (a[i]%2 == 0 ) {
            a2.push_back(a[i]);
        }
        else if (a[i]%3 == 0 ) {
            a3.push_back(a[i]);
        }
        else {
            temp.push_back(a[i]);
        }
    }

    // if ( a6.size() == 0 ) {

    //     if ( (a2.size()==0) || (a3.size()==0) ) {
    //         for ( int num : a ) {
    //             cout << num << " ";
    //         }
    //     }
    //     else {
    //         cout << a2[0] << " ";
    //         cout << a3[0] << " ";
    //         for ( int i=1; i<a2.size(); i++ ) {
    //             cout << a2[i] << " ";
    //         }
    //         for ( int i=1; i<a3.size(); i++ ) {
    //             cout << a2[i] << " ";
    //         }
    //         for ( int& num : temp ) {
    //             cout << num << " ";
    //         }
    //     }

    // }
    // else {
    //     for ( int& num : a6 ) {
    //         cout << num << " ";
    //     }
    //     for ( int& num : a2 ) {
    //         cout << num << " ";
    //     }
    //     for ( int& num : a3 ) {
    //         cout << num << " ";
    //     }
    //     for ( int& num : temp ) {
    //         cout << num << " ";
    //     }
    // }

    int s6 = a6.size();
    int s2 = a2.size();
    int s3 = a3.size();
    int st = temp.size();

    for ( int& num : a6 ) {
        cout << num << " ";
    }
    for ( int& num : a2 ) {
        cout << num << " ";
    }
    for ( int& num : temp ) {
        cout << num << " ";
    }
    for ( int& num : a3 ) {
        cout << num << " ";
    }

    // int i=0;
    // bool flag = true;
    // while ( flag ) {
    //     flag = false;
    //     // if ( i<s6 ) {
    //     //     cout << a6[i] << " ";
    //     //     flag = true;
    //     // }
    //     if ( i<s2 ) {
    //         cout << a2[i] << " ";
    //         flag = true;
    //     }
    //     if ( i<s3 ) {
    //         cout << a3[i] << " ";
    //         flag = true;
    //     }
    //     i++;
    // }

    // for ( int& num : temp ) {
    //     cout << num << " ";
    // }

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