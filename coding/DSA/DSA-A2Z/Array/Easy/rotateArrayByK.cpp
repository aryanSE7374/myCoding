#include<bits/stdc++.h>
using namespace std;



//right rotation : leetcode
// brute force
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n =nums.size();
        k=k%n;
        if(k==0){return;}
        vector<int> temp;
        for (int i = n-k; i < n; i++)
        {
            temp.push_back(nums[i]);
        }
        for(int i = n-k-1 ; i>=0; i--){
            nums[i+k] = nums[i];
        }
        for (int j = 0; j < k; j++)
        {
            nums[j] = temp[j];
        }       
    }
};


// optimal approach using reversal algo

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n =nums.size();
        k=k%n;
        if(k==0){return;}
        reverse(nums.begin(),nums.begin()+n-k);
        reverse(nums.begin()+n-k,nums.end());
        reverse(nums.begin(),nums.end());
    }
};



int main(){
    vector<int> vec;
    for (int i = 0; i < 7; i++)
    {
        vec.push_back(i+1);
    }
    // reverse(vec.begin(),vec.end());
    int k =3;
    int n=7;
    reverse(vec.begin(),vec.begin()+n-k);
    reverse(vec.begin()+n-k,vec.end());
    reverse(vec.begin(),vec.end());
    for (int i = 0; i < 7; i++)
    {
        cout<<vec[i]<<endl;
    }
    
    return 0;
}