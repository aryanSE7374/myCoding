#include<bits/stdc++.h>
#define f(i,a,b) for(int i=a ; i<b ; i++)

using namespace std;

// int count_K_distinctOfSize_W(vector<int> vec , int n , int k , int w ){

//     unordered_map<int , int> mpp;
//     int ans = 0;

//     f(i,0,w){
//         mpp[vec[i]]++;
//     }

//     if(mpp.size()==k) ans++;

//     int l=0 , r=w-1;

//     while(r<n){
//         mpp[vec[l]]--;
//         if(mpp[l]==0){mpp.erase(vec[l]);}
//         l++;
//         r++;

//         if(r<n){
//             mpp[r]++;
//             if(mpp.size()==k) ans++;
//         }

//     }

//     return ans;


// }


int count_K_distinctOfSize_W(vector<int> vec , int n , int k , int w ){

    unordered_map<int , int> mpp;
    int ans = 0;

    f(i,0,w){
        mpp[vec[i]]++;
    }

    if(mpp.size() == k) ans++;

    int l=0 , r=w-1;

    while(r < n-1){
        mpp[vec[l]]--;
        if(mpp[l]==0){mpp.erase(vec[l]);}
        l++;
        r++;
        mpp[vec[r]]++;

        if(mpp.size() == k) ans++;
    }

    return ans;
}



void SOLVE(vector<int> vec , int n , int k , int l , int r){

    int res = 0;

    for(int w = l ; w<=r ; w++){
        if(k<=w){
            res += count_K_distinctOfSize_W(vec , n , k , w );
        }
    }

    cout<<res;
    
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
        SOLVE(vec , n , k , l , r);
        cout<<endl;
    }
    return 0;
}