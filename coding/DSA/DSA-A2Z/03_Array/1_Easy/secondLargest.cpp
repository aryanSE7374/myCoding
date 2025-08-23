#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function returns the second
    // largest elements
    
    int getSecondLargest(vector<int> &arr) {



        int max = arr[0];
        int res = -1;


        for (int i = 1; i < arr.size(); i++)
        {
            if(arr[i]>max){
                res=max;
                max=arr[i];
            }
            else if(arr[i]>res){
                if(arr[i]==max){continue;}
                res = arr[i];
            }
        }
        return res;





        // int max = arr[0]; 
        // int res = arr[1];
        // if(max<res){
        //     // swap(max,res);
        //     max = arr[1];
        //     res = arr[0];
        // }
        // for (int i = 2; i < arr.size(); i++)
        // {
        //     if(arr[i]>max){
        //         res=max;
        //         max=arr[i];
        //     }
        //     else if(arr[i]>res){
        //         if(arr[i]==max){continue;}
        //         res = arr[i];
        //     }
        // }
        // return res;
        // Code Here
    }
};