#include <bits/stdc++.h> 
using namespace std; 

//Naive Solution
int nonRep(string &str) 
{
    for(int i=0;i<str.length();i++){
        bool flag=false;
        for(int j=0;j<str.length();j++){
            if(i!=j&&str[i]==str[j]){
                flag=true;
                break;
            }
        }
        if(flag==false)return i;
    }
    return -1;
}

//Better solution
const int CHAR=256;
int nonRepBetter(string &str) 
{
    int count[CHAR]={0};
    for(int i=0;i<str.length();i++){
        count[str[i]]++;
    }
    for(int i=0;i<str.length();i++){
        if(count[str[i]]==1)return i;
    }
    return -1;
}

//Efficient solution
// const int CHAR=256;
int nonRepEff(string &str) 
{
    int fI[CHAR];
    fill(fI,fI+CHAR,-1);
    
    for(int i=0;i<str.length();i++){
        if(fI[str[i]]==-1)
        fI[str[i]]=i;
        else
        fI[str[i]]=-2;
    }
    int res=INT_MAX;
    for(int i=0;i<CHAR;i++){
        if(fI[i]>=0)res=min(res,fI[i]);
    }
    return (res==INT_MAX)?-1:res;
}
 


int main() 
{ 
    string str = "geeksforgeeks";
    cout<<str<<endl;
    cout<<"Naive Method: ";
    cout<<"Index of leftmost non-repeating element:";
    cout<<nonRep(str)<<endl;  

    cout<<"Better Method: ";
    cout<<"Index of leftmost non-repeating character: ";
    cout<<nonRepBetter(str)<<endl;

    cout<<"Efficient Method : ";
    cout<<"Index of leftmost non-repeating character: ";
    cout<<nonRepEff(str)<<endl;   
    
    return 0; 
} 