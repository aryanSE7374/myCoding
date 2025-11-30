#include <bits/stdc++.h>
using namespace std;


bool checkInf(string s , int n){

    for(int i=0 ; i<n-1 ; i++){
        string subs = s.substr(i, 2);
        if (subs == "**" || subs == "><" || subs == ">*" || subs == "*<") {
            return true;
        }
        // if(s[i]=='*' && s[i+1]=='*') return true;
        // if(s[i]=='>' && s[i+1]=='<') return true;
        // if(s.substr(i,2) == "**" || s.substr(i,2) == "><" ) return true;
    }

    for(int i=0 ; i<n-2 ; i++){
        if(s[i]=='>' && s[i+1]=='*' && s[i+2]=='<') return true;
        // if(s.substr(i,3) == ">*<" ) return true;
    }

    return false;
}
// bool checkInf2(string s , int n){
//     for(int i=0 ; i<n-2 ; i++){
//         if(s.substr(i,2) == "**" || s.substr(i,2) == "><" ) return true;
//     }
//     return false;
// }

int main(){

    int t;
    cin>>t;
    while(t-->0){
        string s;
        cin>>s;

        int n = s.size();
        if(n==1){
            cout<<1<<"\n";
            continue;
        }

        else if(checkInf(s,n)){
            cout<<-1<<"\n";
            continue;
        }

        else{

            int left = 0;
            int right = 0;

            for(int i=0 ; i<n ; i++){

                int l=0;
                int r=0;
                while(i<n && s[i]=='<'){
                    l++;
                    i++;
                }
                while(i<n && s[i]=='>'){
                    r++;
                    i++;
                }
                left = max(left , l);
                right = max(right , r);
                
            }

            cout << max(left , right)<<"\n";

        }

    }

    return 0;

}