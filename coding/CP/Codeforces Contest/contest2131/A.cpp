#include<bits/stdc++.h>
using namespace std;

// try 1

// int Lever(int a[] , int b[] , int n){
//     int iterations = 0;
//     while(true){
        
//         // linear search

//         for( int i=0; i<n ; i++ ){
//             if(a[i]>b[i]){
//                 a[i]--;
//                 break;
//             }
//             if(i==n){ // we didnt found such i
//                 return iterations+1;
//             }
//         }
//         for( int i=0; i<n ; i++ ){
//             if(a[i]<b[i]){
//                 a[i]++;
//                 break;
//             }
//             // if(i==n){ // we didnt found such i
//             //     return iterations++;
//             // }
//         }

//         iterations++;

//     }
//     return 1;

// }




// try 2

int Lever(int a[] , int b[] , int n){
    int iterations = 0;
    while(true){
        // linear search
        // bool changed = false;
        int i=0;

        for(; i<n ; i++ ){
            if(a[i]>b[i]){
                a[i]--;
                for( int j=0; j<n ; j++ ){
                    if(a[j]<b[j]){
                        a[j]++;
                        break;
                    }
                }
                break;
            }
        }

        if(i==n){return iterations+1;}

        // if(!changed){return iterations+1;}
        
        iterations++;

    }
    return 1; // dummy return

}



int main(){
    int t;
    cin>>t;
    while(t-->0){
        int n;
        cin>>n;
        int a[n] ; int b[n];
        for(int i=0 ; i<n ; i++){
            cin>>a[i];
        }
        for(int i=0 ; i<n ; i++){
            cin>>b[i];
        }
        cout<<Lever(a,b,n)<<endl;
    }
    return 0;
}