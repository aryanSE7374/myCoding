#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool canProvideChange(int arr[] , int n){
    int galla[3] = {0,0,0}; //to keep track of no. of Rs. 5,10,20 notes in galla 
    for(int i=0 ; i<n ; i++){
        //if note is of Rs.5 simply add it to galla
        if(arr[i]==5){
            galla[0]++; 
        }
        //if note is of Rs.10 
        else if(arr[i]==10){
            //added to galla
            galla[1]++;
            //check if there's any Rs.5 note or not
            if(galla[0]>0){
                // if yes, then decrement index 0
                galla[0]--;
            }
            
            else{
                //if not then simply return false, indicating that we can't provide chanhge
                return false;
            }
        }
        //if note is of Rs.20
        else{
            //added to galla
            galla[2]++;
            //check if there's a Rs.5 note or not
            if(galla[0]>0){
                //if yes
                if(galla[1]>0){
                    //if there's a Rs.10 note, decrement index 0 and 1 of galla indicating we have returned the change
                    galla[0]--;galla[1]--;
                }
                else{
                    //there's no Rs.10 note, then check if no. of  Rs. 5 notes are greater than 3 or not
                    if(galla[0]>=3){
                        galla[0]--;galla[1]--;
                    }
                    else{
                        //means Rs.5 notes <3
                        return false;
                    }
                }
            }
            else{
                //if there's no Rs.5 note, then return false indicating you can't provide change
                return false;
            }
        }
    }
    return true;
}

int main() {
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    
    int t;
    cin>>t;
    while(t-->0){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
        }
        if(canProvideChange(arr , n)){
            cout<<"true"<<endl;
        }
        else{
            cout<<"false"<<endl;
        }
    }
    
    
    return 0;
}
