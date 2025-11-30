/*
code by - Aryan Shrivastav
*/

/*
observations : 

{
    {   (i-1 , j-1)   , (i-1 , j)  , (i-1 , j+1)   }
    {   (i , j-1)     ,   (i , j)  , (i , j+1)     }
    {   (i+1 , j-1)   , (i+1 , j)  , (i+1 , j+1)   }

}

    if( x > n || y > n ) ans = false;


    for(i=0 ; i<n  ; i++) :
        if (i < x) i++;
        else if (i > x) i--;
        else {}

        if (j < y) j++;
        else if (j > y) j--;
        else {}

    if(i,j) == (x,y) ans = true;



    // ---------- //

    s[n] -> c4,c8

    true <=> max(abs(x) , abs(y)) ≤ c4 + c8   &&   abs(x) + abs(y) ≤ c4 + 2*c8
    else false
    


*/ 

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define co_endl cout<<'\n'
#define f(i,a,n) for(int i=a ; i<n ; i++)

void SOLVE(){

    ll n,x,y;

    cin >> n;
    cin >> x;
    cin >> y;

    string s;
    cin >> s;

    bool ans = false;


// {
//     { (i-1 , j-1) , (i-1 , j) , (i-1 , j+1)   }
//     { (i , j-1) , (i , j) , (i , j+1)   }
//     { (i+1 , j-1) , (i+1 , j) , (i+1 , j+1)   }
// }


    // vector< pair< ll , ll > > pos;

    // pos.push_back({i-1 , j-1});

    ll count4 = 0;
    ll count8 = 0;

    f(i,0,n){
        if(s[i]=='4') count4++;
        else count8++;
    }

    ll x1 = llabs(x);
    ll y1 = llabs(y);

    int maxPos = max(x1 , y1);
    ll maxPos2 = count4 + (2LL * count8);

    if(maxPos > count4 + count8){
        ans = false;
        cout << "NO\n";
        return;
        // cout<<(ans)?"YES\n":"NO\n";
    }

    else if( x1 + y1 > maxPos2){
        ans = false;
        cout << "NO\n";
        return;
        // cout<<(ans)?"YES\n":"NO\n";
    }


    ans = true;
    cout << "YES";

    // cout<<(ans)?"YES\n":"NO\n";

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

