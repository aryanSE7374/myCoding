#include<bits/stdc++.h>
using namespace std;


// void SOLVE(vector<int>& str , int n , unordered_map<int , int> mpp){
void SOLVE(vector<int>& str , int n ){
    // vector<int> revNums(n-mpp.size() , 0);
    vector<int> revNums;
    for(int i=0 ; i<n ; i++){
        if(str[i]==0){
            revNums.push_back(i+1);
        }
        // if(mpp.find(i+1)==mpp.end()){
        //     revNums.push_back(i+1);
        // }
    }
    sort(revNums.begin(), revNums.end(), greater<int>());

    int k = revNums.size()-1;

    for(int i=0 ; k>=0 && i<n ; i++){
        if(str[i]==0){
            str[i] = revNums[k];
            k--;            
        }
    }


    for(int s : str){
        cout<<s<<" ";
    }

}


// void generateRevSorted(int n){
//     for (int i = 0; i < n; i++)
//     {
//         cout<<n-i<<" ";
//     }
// }

int main(){

    int t;
    cin>>t;
    while(t-->0){
        int n;
        cin>>n;
        string s;
        cin>>s;
        vector<int> str(n,0);
        // unordered_map<int , int> mpp;
        for(int i=0 ; i<n ; i++){
            // cin>>str[i];
            if(s[i]=='1'){
                // mpp[i+1]++;
                str[i]=i+1;
            }
        }

        // if(mpp.size() == 0){
        //     generateRevSorted(n);
        // }

        SOLVE(str , n );

        cout<<endl;

    }

    return 0;
}