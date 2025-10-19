#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string& str){
    string reversed_str = str;
    reverse(reversed_str.begin() , reversed_str.end());
    return str == reversed_str;
}

bool checkNonDec(string& str){
    int n = str.size();
    for(int i = 1 ; i < n ; i++)
        if(str[i] < str[i - 1]){ return false;}
    return true;
}

bool helper(int idx , string & s , string & p , vector<int>& ans){

    int n = s.size();

    if(idx == n){

        string temp;

        vector<bool> rejected(n , false);

        for(int id : ans) rejected[id] = true;

        for(int i = 0 ; i < n ; i++)
            if(!rejected[i]) temp.push_back(s[i]);

        if(checkNonDec(p) && isPalindrome(temp)) return true;

        return false;

    }

    // Option 1: skip s[idx]
    if (helper(idx + 1 , s , p , ans)) return true;

    // Option 2: take s[idx]
    p.push_back(s[idx]);
    ans.push_back(idx);
    if (helper(idx + 1 , s , p , ans)) return true;
    p.pop_back();
    ans.pop_back();

    return false;
}

void SOLVE(string& s , int n) {
    
    if(isPalindrome(s)){
        cout << 0 << endl;
        return ;
    }

    string p;
    vector<int> ans;

    bool res = helper(0 , s , p , ans);

    if(!res){
        cout << -1 << endl;
        return;
    }

    int n = ans.size();
    cout << n << endl;
    for (int i = 0; i < n; i++) {
        cout << ans[i] + 1 << " ";
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        SOLVE(s, n);
        cout << endl;
    }

    return 0;
}