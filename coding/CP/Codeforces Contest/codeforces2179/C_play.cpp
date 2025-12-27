/*
code by - Aryan Shrivastav
*/

/*
observations : 


ferq_s , ferq_t , ferq_t-s , 

s = "aryanshrivastav"
t = <string> : s is a subset of all characters in t

feq_t -> a : a_t , 
         b : b_t , 
         c : c_t , ... till z
         
lly freq_t-s[c] = freq_t[c] - freq_s[c]

=>

feq_t-s ->  a : a_t , 
            b : b_t , 
            c : c_t , ... till z

            if x=a to z -> freq_t-s < 0 : 
                return impossible

            else :
                ans = a*(a_t-s) + b*(b_t-s) + c*(c_t-s) + d*(d_t-s) + e*(e_t-s) + f*(f_t-s) + ... + z*(z_t-s) 

                int p = 0; // pointer to chars in s
                char maxi = s[p]
                while(p<n){
                    curr location = last char that matches to maxi in ans
                    move to curr location of p in ans and implant the char at s[p] in ans after the maxi char location
                    and after that -> till the chars in s (p+1 to n) are less than equal to maxi , keep adding them after the curr location (i.e. before maxi+1 character),p++

                    if(s[p] > maxi) :
                        repeat the same process till p<n
                }


            return ans;



*/ 

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define co_endl cout<<'\n'
#define f(i,a,n) for(int i=a ; i<n ; i++)


void SOLVE(){

    string s,t;
    cin >> s;
    cin >> t;

    int len_s = s.size();
    int len_t = t.size();

    vi freq_s(26,0);
    vi freq_t(26,0);
    vi freq_t_s(26,0); // ferq_t-s

    for(char& c : s){
        freq_s[c-'a']++;
    }
    for(char& c : t){
        freq_t[c-'a']++;
    }
    f(i,0,26){
        freq_t_s[i] = freq_t[i] - freq_s[i];
    }

    string ans = "";

    f(i,0,26){
        freq_t_s[i] = freq_t[i] - freq_s[i];
        if(freq_t_s[i] < 0){
            ans = "Impossible\n";
            cout << ans;
            return;
        }
        // else if(freq_t_s[i] == 0){continue;}
        // else{
        //     string temp(freq_t_s[i] , (char)('a'+i));
        //     ans.append(temp);
        // }
    }

    // for(char& c : s){
    //     int maxi = c - 'a';
    //     f(i,0,maxi){
    //         while(freq_t[i] > freq_s[i]){
    //             ans += (char)('a' + i);
    //             freq_t[i]--; 
    //         }
    //     }

    //     ans += c;

    //     freq_t[maxi]--;
    //     freq_s[maxi]--;
    // }

    // f(i,0,26){
    //     while(freq_t[i] > 0){
    //         ans += (char)('a' + i);
    //         freq_t[i]--;
    //     }
    // }

    // cout << ans;
    // co_endl;
    // return;


    // ----- // 
    vi last_idx(26,0);
    f(i,0,26){
        string temp(freq_t_s[i] , char('a'+i));
        ans.append(temp);
        last_idx[i] = ans.size()-1;
    }

    int p=0;
    int curr = 0;
    char maxi = s[p];
    int p0 = 0;

    while(p<len_s){
        string temp = "";
        while(p<len_s && s[p]<=maxi){
            temp+=s[p];
            p++;
        }

        ans.insert( last_idx[maxi-'a'] + p0 + 1  , temp);

        p0 = p;

        if(p >= len_s){
            break;
        }
        else{
            maxi = s[p];
        }

    }


    cout << ans;


    co_endl;
}

int main(){

    int t;
    cin>>t;
    while(t-->0){

        SOLVE();

    }

    return 0;
}