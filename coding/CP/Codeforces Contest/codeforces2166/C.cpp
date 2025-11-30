#include<bits/stdc++.h>
using namespace std;
#define ll long long
using pll = pair<ll, int>;

ll mini(ll a , ll b , ll c , ll d){
    ll res = INT_MAX;
    res = min(res , a);
    res = min(res , b);
    res = min(res , c);
    res = min(res , d);
    return res;
}

// void SOLVE(){
//     int n;
//     cin >> n;
//     vector<ll> arr(n);
//     for(int i = 0 ; i<n ; i++){
//         cin>>arr[i];
//     }

//     vector<ll> cyc_dp(n,0);
//     vector<ll> acyc_dp(n,0);

//     // cyc_dp[0] = max(arr[0] , arr[n-1]);
//     cyc_dp[0] = max(arr[0] , arr[n-1]);
    
//     for (int i = 1; i < n; i++){
//         cyc_dp[i] = max(arr[i] , cyc_dp[i-1]);
//     }

//     acyc_dp[n-1] = max(arr[0] , arr[n-1]);

//     for (int i = n-2; i >= 0; i--){
//         acyc_dp[i] = max(arr[i] , acyc_dp[i+1]);
//     }

//     ll ans = 0;

//     for(int i=1 ; i<n-1 ; i++){
//         ans += min(cyc_dp[i] , acyc_dp[i]);
//     }
//     ans += mini(cyc_dp[0] , acyc_dp[0] , cyc_dp[n-1] , acyc_dp[n-1]);

//     cout << ans << "\n";
    

// }





void SOLVE(){
    int n;
    cin >> n;
    vector<ll> arr(n);

    vector<int> prev_dp(n);
    vector<int> next_dp(n);

    vector<bool> exist(n , true); 

    
    // val , idx
    priority_queue<pll , vector<pll> , greater<pll>> pq;

    for(int i = 0 ; i<n ; i++){

        cin>>arr[i];

        prev_dp[i] = (i - 1 + n) % n ;
        next_dp[i] = (i + 1) % n ;

        pq.push( {arr[i], i} );

    }

    
    if(n == 1){
        cout << 0 << "\n";
        return;
    }

    ll ans = 0;
    
    for(int k = 0 ; k < n-1; k++){
        
        pll top = pq.top();
        pq.pop();
        
        ll val = top.first;
        int i = top.second;

        if(!exist[i]){
            k--;
            continue;
        }


        int p = prev_dp[i];
        int next_i = next_dp[i];
        ll val_p = arr[p];
        ll val_n = arr[next_i];


        ll cost_p = max(val, val_p);
        ll cost_n = max(val, val_n);

        if(cost_p <= cost_n){

            ans += cost_p;
            arr[p] = cost_p;
            
            exist[i] = false;
            
            next_dp[p] = next_i;
            prev_dp[next_i] = p;
            
            pq.push({arr[p], p});

        } 
        else{

            ans += cost_n;
            arr[next_i] = cost_n;

            exist[i] = false;

            next_dp[p] = next_i;
            prev_dp[next_i] = p;

            pq.push({arr[next_i], next_i});
        }
    }

    cout << ans << "\n";
}


int main(){

    int t;
    cin>>t;
    while(t-->0){
      SOLVE();
    }

    return 0;
}