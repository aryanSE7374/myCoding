#include<bits/stdc++.h>
using namespace std;

string Homework(string a , string b , string c , int m){

    string res = a;

    for(int i=0 ; i<m ; i++){
        if(c[i]=='D'){
            res = res + b[i];
        }
        else{
            res = b[i] + res;
        }
    }

    return res;

}


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n; // length of a
        cin >> n;
        string a;
        cin >> a;

        int m; // length of b, c
        cin >> m;
        string b, c;
        cin >> b >> c;

        cout << Homework(a, b, c , m) << endl;
    }
    return 0;
}