#include<bits/stdc++.h>
using namespace std;

int shiftSort(vector<int> str , int n){
    vector<int> zeroesMap; // store indices of 0s and 1s
    vector<int> onesMap;
    for(int i=0 ; i<n ; i++){
        if(str[i]==1){
            onesMap.push_back(i);
        }
        else{
            zeroesMap.push_back(i);
        }
    }
    int zeroes = zeroesMap.size();
    int ones = onesMap.size();
    // traverse zeroes form back and ones from front and then apple codition : 
    // {
    // j=n-i-i
    // ones[i]<ones[i+1]<zeroes[j] - right shift
    // ones[i]<zeroes[j]<ones[i+1] - left shift
    // zeroes[j]<ones[i]<ones[i+1] - break and return i or count variable
    // }
    for()
    while(zeroes>0 && ones>0){

    }
}

int main(){
    int t;
    cin>>t;
    while(t-->0){
        int n;
        cin>>n;
        vector<int> str(n);
        for(int i=0 ; i<n ; i++){
            cin>>str[i];
        }

        cout<<shiftSort(str , n);

        cout<<endl;


    }
    return 0;
}