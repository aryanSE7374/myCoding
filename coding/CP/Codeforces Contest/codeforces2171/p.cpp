#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool dfs(vector<int>&choice, vector <int>&ans, int n , int track,int target,int start){

        if(track==n+1){
            return accumulate(ans.begin(),ans.end(),0)==target;}

        for(int i =start+1;i<choice.size();i++){
            ans.push_back(choice[i]);
            if(dfs(choice,ans,n,track+1,target,i))
                {return true ;}
            ans.pop_back();
        }

        return false ;
    }

    vector<int> lexSmallestNegatedPerm(int n, long long target) {

        vector<int>choice;
        for(int i =-n ;i<=n;i++){
            if(i==0)continue ;
            choice.push_back(i);
        }
        vector<int>ans;


        dfs(choice,ans ,n,1,target,-1);
        return ans ;
        
    }
};