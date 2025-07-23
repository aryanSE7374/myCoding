#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to count the frequency of all elements from 1 to N in the array.
    vector<int> frequencyCount(vector<int>& arr) {
        // code here
        vector<int> vec;
        unordered_map<int,int> mpp;
        for (int i = 0; i < arr.size(); i++)
        {
            mpp[arr[i]]++;
        }
        
        for (int i = 1; i <= arr.size(); i++)
        {
            vec.push_back(mpp[i]);
        }
        return vec;
    }
};




int main(){

    vector<int> arr;
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(6);
    arr.push_back(9);

    vector<int> vec;
    unordered_map<int,int> mpp;
    for (int i = 0; i < arr.size(); i++)
    {
        mpp[arr[i]]++;
    }
    for(auto it : mpp){
        cout<<it.first<<"->"<<it.second<<endl;
    }
    for (int i = 1; i <= arr.size(); i++)
    {
        vec.push_back(mpp[i]);
    }
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<i+1<<" : "<<vec[i]<<endl;
    }
    

    return 0;
}