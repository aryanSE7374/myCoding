#include<bits/stdc++.h>
#define f(i,a,b) for(int i=a ; i<b ; i++)

using namespace std;

long long countAtMost(vector<int>& a, int k, int w){
    
    if(k<0) return 0;
    int n = a.size();

    unordered_map<int,int> mpp;

    long long ans=0;

    int l=0;

    for(int r = 0 ; r<n ; r++){
        mpp[a[r]]++;
        while ((int)mpp.size() > k){
            mpp[a[l]]--;
            if (mpp[a[l]] == 0) mpp.erase(a[l]);
            l++;
        }

        while (r-l+1 > w){
            mpp[a[l]]--;
            if (mpp[a[l]]==0) mpp.erase(a[l]);
            l++;
        }
        ans += (r-l+1); 
    }
    return ans;
}

long long SOLVE(vector<int>& a, int n , int k, int l, int r){
    return (countAtMost( a , k , r) - countAtMost(a , k , l - 1 ) ) - (countAtMost( a, k - 1 , r ) - countAtMost( a , k - 1 , l - 1 ) );
}


int main(){
    int t;
    cin>>t;
    while(t-->0){
        int n;
        int k;
        int l;
        int r;

        cin>>n;
        cin>>k;
        cin>>l;
        cin>>r;

        vector<int> vec(n,0);
        f(i,0,n){
            cin>>vec[i];
        }
        cout<<SOLVE(vec , n , k , l , r);
        cout<<endl;
    }
    return 0;
}
