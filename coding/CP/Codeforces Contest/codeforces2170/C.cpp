/*
code by - Aryan Shrivastav
*/

/*
observations : 


    q[n] , r[n] , k

    def operation : 
        - select x,y : 1 <= y < x <= k <=> 
            there exists i s.t.  q[i] = floor(x/y) &&  -- case1
            there exists j s.t.  r[j] = (x%y)          -- case2

            remove any one instance of q[i] from q and r[j] from j


    observation - 
        1. maintain a freq vector , after every vaid op : freq[q[i]]--; freq[r[j]]--; (not needed anymore)
        2. how to select x and y??
        3. since y<x && 1 <= y && x <= k  
            --> x!=y
            --> min(y) = 1 and max(y) = k-1
            --> min(x) = 2 and max(x) = k
  
        4. pos1 = count all possibilities to perform case 1 i.e. max(x) >= min(y)*q[i] -> k => q[i]*1
        5a. pos2 = count all possibilities to perform case 2 i.e. max(x) - min(y) >= r[j] -> k-1 >= r[j]
        5b. pos2 = count all possibilities to perform case 2 i.e. max(x) - r[j] >= r[j] -> k-1 >= r[j]
        5c. pos2 = count all possibilities to perform case 2 i.e. max(x) - r[j] >= r[j] -> k-1 >= r[j] {iff k-r[j] >=r[j] --->> k>= 2*r[j]  }
        6. ans = min(pos1,pos2)


*/ 

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define co_endl cout<<'\n'
#define f(i,a,n) for(int i=a ; i<n ; i++)

void SOLVE(){

    ll n , k;
    cin >> n >> k;

    vll q(n);
    vll r(n);

    f(i,0,n){
        cin >> q[i];
    }
    
    f(i,0,n){
        cin >> r[i];
    }

    // ll pos1 = 0;
    // ll pos2 = 0;

    // f(i,0,n){

    //     if(k >= q[i]) pos1++;
    //     // if( k-1 > (2*r[i]) &&  k-1-r[i] > r[i]) pos2++;
    //     if( k >= (2*r[i])+1 ) pos2++;

    // }
    
    // ll ans = min(pos1 , pos2);


    sort(q.begin() , q.end());
    sort(r.begin() , r.end());

    reverse(q.begin() , q.end());

    ll ans = 0;

    ll i=0 , j=0;

    while(i<n && j<n ){

        ll y_min = r[j]+1;
        ll y_max = (k-r[j])/q[i];

        ll r_max = (k-q[i])/(q[i]+1);

        // if(y_min > y_max){
        //     i++;
        // }

        if(r[j] <= r_max){
            ans++;
            i++;
            j++;
        }

        else{
            i++;
        }

    }

    cout << ans;

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