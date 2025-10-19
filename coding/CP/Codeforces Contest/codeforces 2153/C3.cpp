#include <bits/stdc++.h>
using namespace std;

long long findMaxPerimeter( map<long long,int> freq , long long totalSum ){

    vector<long long> oddLens;
    for(auto &it : freq){
        if(it.second%2 != 0){
            oddLens.push_back(it.first);
        }
    }
    
    sort(oddLens.begin(), oddLens.end());
    // while(oddLens.size() > 2){
    //     totalSum -= oddLens[0];
    //     freq[oddLens[0]]--;
    //     if(freq[oddLens[0]] == 0) freq.erase(oddLens[0]);
    //     oddLens.erase(oddLens.begin());
    // }

    int remCnt = oddLens.size() - 2;

    for(int i = 0 ; i < remCnt ; i++){
        totalSum -= oddLens[i];
        freq[oddLens[i]]--;
        if( freq[ oddLens[i] ] == 0 ) freq.erase(oddLens[i]);
    }
    
    if(freq.empty()) return 0;
    
    long long largest = freq.rbegin()->first;

    if( 2 * largest < totalSum ) return totalSum;

    return totalSum - largest;
    
}

void SOLVE(vector<long long>& arr){

    if(arr.size()==3){
        sort(arr.begin() , arr.end());
        if(arr[0]+arr[1]<=arr[2]){
            cout<<0;
            return;
        } 

    }

    int n = arr.size();

    map< long long , int > freq;

    long long totalSum = 0;
    long long maxLen = 0;

    for(long long len : arr){
        freq[len]++;
        totalSum += len;
        maxLen = max(maxLen , len);
    }

    // case 1

    long long res1 = findMaxPerimeter(freq , totalSum);

    // case 2

    if(n > 0){
        freq[maxLen]--;
        if(freq[maxLen] == 0) freq.erase(maxLen);
    }

    long long res2 = findMaxPerimeter(freq , totalSum - maxLen);

    cout<<max(res1, res2);
}


int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
        }

        SOLVE(arr);
        cout<<endl;

    }

    return 0;
}