#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {

int row=numRows;

int a=0;
int i=0;
vector<vector<char>> v(row);

while(a<s.size()){

if(i==0){
for(; i<row && a<s.size(); i++){
v[i].push_back(s[a]);
a++;
}
}

if(i==row){
i-=2;
for(; i>0 && a<s.size(); i--){
v[i].push_back(s[a]);
a++;
}
}
i=0;

}

string x="";


for(int a=0; a<v.size(); a++){
for(int b=0; b<v[a].size(); b++){
x+=v[a][b];
}
}

return x;
        

        
    }
};