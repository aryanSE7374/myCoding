#include<bits/stdc++.h>
using namespace std;

void Frequency(int arr[], int n)
{
    unordered_map<int , int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }
    for(auto it  : mpp){
        cout<<it.first<<"->"<<it.second<<endl;
    }
}