#include <bits/stdc++.h>
using namespace std;

// void SOLVE(vector<int> &p , int n){

//     vector<int> prefMax(n+1, 0);

//     for(int i = 0; i < n; i++){
//         prefMax[i+1] = max(prefMax[i], p[i]);
//     }

//     int l=0;

//     while(l<n && prefMax[l+1] == l+1){
//         l++;
//     }

//     vector<int> suffMin(n+1, n+1);

//     for(int i = n-1; i >= 0; i--){
//         int temp = p[i];
//         if(p[i]==0){
//             temp =  n+1;
//         }

//         suffMin[i] = min(suffMin[i+1] , temp);
//     }

//     int r=n;

//     while(r>0 && suffMin[r-1] == r){
//         r--;
//     }

//     if (l >= r) cout<<0;
//     else cout << r-l;
// }


void SOLVE(vector<int> &p , int n){
    vector<int> prefMax(n+1, 0);
    for(int i=0; i<n; i++){
        prefMax[i+1] = max(prefMax[i], p[i]);
    }

    int l = 0;
    while(l<n && prefMax[l+1] == l+1) l++;

    vector<int> suffMin(n+1, n+1), suffMax(n+1, 0);
    for(int i=n-1; i>=0; i--){
        int temp = (p[i]==0 ? n+1 : p[i]);
        suffMin[i] = min(suffMin[i+1], temp);

        int temp2 = (p[i]==0 ? 0 : p[i]);
        suffMax[i] = max(suffMax[i+1], temp2);
    }

    int r = n;
    while(r>0 && suffMin[r-1] == r && suffMax[r-1] == n){
        r--;
    }

    if(l >= r) cout << 0;
    else cout << r-l;
}

int main(){
    int t;
    cin>>t;
    while(t-->0){
        int n;
        cin>>n;
        vector<int> p(n,0);
        for(int i=0 ; i<n ; i++){
            cin>>p[i];
        }

        SOLVE(p , n);

        cout<<endl;

    }
    return 0;
}
