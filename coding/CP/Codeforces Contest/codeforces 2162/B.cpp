#include<bits/stdc++.h>
using namespace std;


bool isPalindrome(string& str) {
    string reversed_str = str;
    reverse(reversed_str.begin(), reversed_str.end());
    return str == reversed_str;
}

void SOLVE(string& s , int n){

    if(isPalindrome(s)){
        cout << 0 << endl;
        return ;
    }

    // string temp;
    int count = 0;
    vector<int> ans;
    for(int i=0 ; i<n ; i++){
        if(s[i]=='0') {
            count ++;
            ans.push_back(i);
        }
    }

    cout << count << endl;

    for(int num : ans) { 
        cout << num+1 << " ";
    }
    
}

int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin >> s;
        SOLVE(s,n);
        cout<<endl;

    }

    return 0;
}