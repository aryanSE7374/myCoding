// /** Coded by - MODERAX **/
// //#define NIGGA
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<sstream>
#include<cmath>
#include<random>
#include<chrono>
#include<map>
#include<climits>
#include<unordered_set>
#include<queue>
#include<unordered_map>
#include<functional>
#include<bitset>
#include<set>
#include<list>
#include<iterator>
#include<utility>
#include<array>
#include<tuple>
#include<complex>
#include<limits>
#include<fstream>
#include<ctime>
#include<cstring>
#include<cstdio>
#include<cstdlib> 
#include<cassert>
#include<stack>
#include<numeric>
#include<initializer_list>
#include<type_traits>
#include<regex>
#include<valarray>

#ifdef NIGGA
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> _pbds;
#endif

using namespace std;

#define int long long
#define pb push_back
#define all(v) v.begin(), v.end()
#define vi vector<long long>
#define vvi vector<vector<long long> >
#define vvc vector<vector<char> >
#define vs vector<string>
#define vb vector<bool>
#define vp vector<pair<int,int> >
#define f(i,a,b) for(int i=a;i<b;i++)
#define of(i,a,b) for(int i=a;i>=b;i--)
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
#define endl '\n'

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
int randInt(int l,int r){return uniform_int_distribution<int>(l,r)(RNG);} 

const int MOD = 998244353;
const int mod = 1e9+7;
const int INF = 1e6;

void SOLVE_BLOCK(){
    int n; cin>>n;
    vector<string>arr(n);
    f(i,0,n) cin>>arr[i];
    int k; cin>>k;
    //
   // sort(all(arr));
    int count=0;
    f(i,0,n-1){
        if(arr[i]==arr[i+1]) count++;
        else count=0;
        if(count==k-1){
            cout<<arr[i]<<endl;
            return;
        }
    }
    cout<<"None"<<endl;
}

signed main(){
    #ifdef NIGGA
    auto begin = chrono::high_resolution_clock::now();
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);

    int __ =1;
    //cin >> __;
    f(i,1,__+1) {
       // cout<<"#Case no : "<<i;
        SOLVE_BLOCK();
    }

    #ifdef NIGGA
    auto end = chrono::high_resolution_clock::now();
    cerr << "Time measured: " 
        << chrono::duration_cast<chrono::milliseconds>(end-begin).count()
        << " ms\n";
    cerr.flush();
    #endif
}