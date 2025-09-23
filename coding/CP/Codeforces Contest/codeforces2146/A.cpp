#include<bits/stdc++.h>
using namespace std;


// int SOLVE(vector<int>& vec , int n){
//     unordered_map<int , int> freq;
//     for(int num : vec){
//         freq[num]++;
//     }
//     vector<int> freqTable;
//     for(auto it : freq){
//         freqTable.push_back(it.second);
//     }

//     sort(freqTable.begin() , freqTable.end());

//     int maxi = 0;
//     int m = freqTable.size();
//     int k=0;
//     for(int i=0 ; i<m ; i++){
//         if(i>0 && freqTable[i-1]!=freqTable[i]){
//             k++;
//         }
//         int val = freqTable[i]*(m-k);
//         maxi = max(maxi , val);
//     }

//     return maxi;

// }


int SOLVE(vector<int>& vec , int n){
    unordered_map<int , int> freq;
    for(int num : vec){
        freq[num]++;
    }
    vector<int> freqTable;
    for(auto it : freq){
        freqTable.push_back(it.second);
    }

    int maxi = 0;
    int m = freqTable.size();

    for(int f : freqTable){
        int cnt = 0;
        for(int x : freqTable){
            if(x>=f) cnt++;
        }
        maxi = max(maxi, f*cnt);
    }

    return maxi;

}

int main(){

    int t;
    cin>>t;
    while(t-->0){
        int n;
        cin>>n;
        vector<int> vec(n,0);
        for(int i=0 ; i<n ; i++){
            cin>>vec[i];
        }

        cout<<SOLVE(vec , n);
        cout<<endl;

    }

    return 0;
}