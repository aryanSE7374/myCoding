#include<bits/stdc++.h>
using namespace std;

int shiftSort(string s, int n) {
    string sortedStr = s;
    sort(sortedStr.begin(), sortedStr.end());

    if(s == sortedStr) return 0; 

    int m = 0;

    for(int i=0 ; i<n ; i++){
        if ( ( s[i] != sortedStr[i] ) && (s[i]=='1')){
            m++;
        }
    }

    return m;

    // int left = 0;
    // while(left<n && s[left] == sortedStr[left]) left++;

    // int right=n-1;

    // while(right>=0 && s[right] == sortedStr[right]) right--;

    // bool flag = false;

    // for(int i=left; i<=right; i++){
    //     if(s[i]=='0') flag = true;
    //     if(s[i]=='1' && flag) return 2;
    // }
    // return 1;
}


int main(){
    int t;
    cin>>t;
    while(t-->0){
        int n;
        cin>>n;
        string str;
        cin>>str;

        cout<<shiftSort(str , n);

        cout<<endl;


    }
    return 0;
}