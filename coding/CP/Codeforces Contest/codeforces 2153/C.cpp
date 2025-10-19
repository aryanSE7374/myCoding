#include<bits/stdc++.h>
using namespace std;


void SOLVE(vector<int>& arr){

    if(arr.size()==3){
        sort(arr.begin() , arr.end());
        if(arr[0]+arr[1]<=arr[2]){
            cout<<0;
            return;
        } 

    }

    long long perimeter = 0;

    // unordered_map<int , int> freq;
    map<int , int> freq;

    for(int num : arr){
        freq[num]++;
    }

    for(auto &it : freq){
        int fr = it.second;
        if(fr>=2){
            perimeter += 1LL*(fr/2)*2*it.first;    
            it.second%=2;
            // if(it.second == 0 ) freq.erase(it.first);
        }
    }

    if(perimeter!=0){
        int k = 2;
        for (auto it = freq.rbegin() ; k>0 && it != freq.rend()  ; it++){
            // perimeter += it->first;
            // if(it->first != 0){
            //     k--;
            // }
            if(it->second == 1){
                perimeter += it->first;
                k--;
            }
            
        }
    }

    cout<<perimeter;

}

int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
        }

        SOLVE(arr);
        cout<<endl;

    }

    return 0;
}