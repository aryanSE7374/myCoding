#include <bits/stdc++.h> 
using namespace std; 

// TC : O()
// AS : O()

//Naive Method
// TC : O(n²)
// AS : O(1)
int leftMost(string &str) 
{
    for(int i=0;i<str.length();i++){
        for(int j=i+1;j<str.length();j++){
            if(str[i]==str[j])return i;
        }
    }
    return -1;
}
//Better Solution
// TC : O(n)  but req two traversals
// AS : O(CHAR)
const int CHAR=256;
int leftMostBetter(string &str) 
{
    //count array of all the 256 ASCII characters with their ASCII code as index
    int count[CHAR]={0};
    for(int i=0;i<str.length();i++){
        count[str[i]]++; //count[str[i]] = count[g] = count[ASCII('g')]
    }
    for(int i=0;i<str.length();i++){
        if(count[str[i]]>1)return i; //return the first appeared count more than 1
    }
    return -1; //else if all elements are distinct than in that case
}

//Efficient sol 1
// const int CHAR=256;
// TC : O(n)
// AS : O(CHAR)
int leftMostEff1(string &str) 
{
    int fIndex[CHAR]={0};//first index table of size 256
    fill(fIndex,fIndex+CHAR,-1);//fill every index of first Index table as -1 indicating not visited yet
    int res=INT_MAX; //initialize res 
    for(int i=0;i<str.length();i++){
        int fi=fIndex[str[i]]; // for every element define fi as fIndex['g'] = fIndex[ASCII('g')] , 
        //i.e. if 'g' is not visited yet => fi=(-1)
        if(fi==-1)
        fIndex[str[i]]=i; //put the first appearing index in the fIndex table
        else
        res=min(res,fi); //if visited earlier , update the result if the first index of visit < the current result
    }
    
    return (res==INT_MAX)?-1:res;
}
 
//efficient sol 2
// const int CHAR=256;
int leftMostEff2(string &str) 
{
    // the optimisation made in this solution is based on the fact that we travels our visited array from
    // right to left ,Also We use A boolean array Instead of the integer one.
    // Travels from right to left. Make sure that we find the index of the left most repeating element 
    // In the end of our traversal, if there exist a left Most repeating index.
    // The optimisation made here removes overhead to check the result again and again if the element
    // Is appearing more than first time, You don't need to check it again and again
    
    bool visited[CHAR];
    fill(visited,visited+CHAR,false);
    int res=-1; //initialize on assumption that there's no repeating element
    for(int i=str.length()-1;i>=0;i--){
        // If the array is marked as true, this implies we visited element, and we simply update the result
        if(visited[str[i]])
        res=i;
        //if false , This implies we haven't visited the element yet, and we update The visited table as true
        else
        visited[str[i]]=true;
    }
    return res;
}



int main() 
{ 
    string str = "geeksforgeeks";
    cout<<str<<endl;
    cout<<"Naive Method: ";
    cout<<"Index of leftmost repeating character: ";
    cout<<leftMost(str)<<endl;

    cout<<"Better Method: ";
    cout<<"Index of leftmost repeating character: ";
    cout<<leftMostBetter(str)<<endl;   

    cout<<"Efficient Method 1: ";
    cout<<"Index of leftmost repeating character: ";
    cout<<leftMostEff1(str)<<endl;   

    cout<<"Efficient Method 2: ";
    cout<<"Index of leftmost repeating character: ";
    cout<<leftMostEff2(str)<<endl;   

    return 0; 
}