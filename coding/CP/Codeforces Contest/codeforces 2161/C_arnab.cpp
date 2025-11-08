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
 
const int mod = 998244353;
const int MOD = 1e9+7;
const int INF = 1e6;


// const vi a={-1,1,0,0};
// const vi b={0,0,-1,1};


void SOLVE_BLOCK(){
    int n,X;cin>>n>>X;
    vi a(n);
    int sum=0;
    f(i,0,n){
        cin>>a[i];
        sum+=a[i];
    }
    int c=sum/X;
    vi d=a;
    sort(all(d));
    int maxx=0;
    f(i,0,c)maxx+=d[n-1-i];
    deque<int> small,large;
    f(i,0,n-c)small.pb(d[i]);
    f(i,n-c,n)large.pb(d[i]);
    vi ans;
    int f1=0;
    f(i,0,n){
        if(!small.empty()){
            int g=small.front();
            if(f1+g<X){
                ans.pb(g);
                small.pop_front();
                f1+=g;
            }
            else{
                if(!large.empty()){
                    int h=large.back();
                    ans.pb(h);
                    large.pop_back();
                    f1=(f1+h)%X;
                }
                else{
                    ans.pb(g);
                    small.pop_front();
                    f1=(f1+g)%X;
                }
            }
        }
        else{
            int h=large.front();
            ans.pb(h);
            large.pop_front();
            f1=(f1+h)%X;
        }
    }
    cout<<maxx<<endl;
    f(i,0,n)cout<<ans[i]<<" ";
    cout<<endl;
}
signed main(){
    #ifdef NIGGA
    auto begin = chrono::high_resolution_clock::now();
    #endif
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);
 
    int __ =1;
    cin >> __;
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