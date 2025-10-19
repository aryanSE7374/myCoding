#include<bits/stdc++.h>
using namespace std;


bool checkPallindrome(string& str){
    string reversed_str = str;
    reverse(reversed_str.begin(), reversed_str.end());
    return str == reversed_str;
}

void makeSymBR(string& symBR) {
    int n = symBR.size();

    while (true) {
        bool isSym = true;
        int len = symBR.size();
        for (int i = 0; i < len / 2; i++) {
            if (symBR[i] != symBR[len - 1 - i]) {
                isSym = false;
                break;
            }
        }
        if (isSym) break;
        symBR = "0" + symBR;       
    }
}


void SOLVE(int n){

    if (n == 0) { cout << "NO"; return; }

    int rm = n & (-n);
    int k = int(log2(rm)) + 1;

    string bR = bitset<8>(k).to_string();

    string symBR = bR;

    int bRsz = bR.size();
    if(checkPallindrome(bR)){
        if(bRsz%2==1){
            if(bR[bRsz/2]=='0'){
                cout<<"YES";
                return;
            }
            else{
                // make bR -> symBR
                // if()
            }
        }
        else{
            cout<<"YES";
            return;
        }
    }
    
    else{
        makeSymBR(symBR);
        if(checkPallindrome(symBR)){
            if(bRsz%2==1){
                if(bR[bRsz/2]==0){
                    cout<<"YES";
                    return;
                }
                else{
                    // make bR -> symBR
                    // if()
                }
            }
            else{
                cout<<"YES";
                return;
            }
        }
        else{
            cout<<"NO";
            return;
        }
    }


}

int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        // vector<int> arr(n);
        // for(int i=0 ; i<n ; i++){
        //     cin>>arr[i];
        // }
        SOLVE(n);
        cout<<endl;

    }

    return 0;
}