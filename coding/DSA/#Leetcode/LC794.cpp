#include<bits/stdc++.h>
using namespace std;



// NOT SOLVED yet



// class Solution {
// public:
//     bool isWinning(int num){
//         return (num%3)==0;
//     }
// public:
//     bool validTicTacToe(vector<string>& board) {
//         int countX = 0; int corSumX = 0;
//         int countO = 0; int corSumO = 0;
//         int spaceCount = 0;
//         for(int i=0 ; i<3 ; i++){
//             // cout<<board[i]<<endl;
//             for(int j=0 ; j<3; j++){
//                 if(board[i][j]=='O'){countO++;corSumO+=(i+j);}
//                 else if(board[i][j]=='X'){countX++;corSumX+=(i+j);}
//                 else{spaceCount++;}
//             }
//         }
//         if((countX!=0)&&(countX-1!=countO)){return false;}
//         return ((!isWinning(corSumO))||(!isWinning(corSumX)));
//     }
// };

class Solution {
public:
/*
0,0 0,1 0,2
1,0 1,1 1,2
2,0 2,1 2,2


<0,0> <0,1> <0,2>


*/
    bool isWinning(vector<vector<int>> vec,int cordSum){
        if(vec.size()<3){return false;}
        
        // else if(vec.size()==3){return cordSum%3==0;}
        // else if(vec.size()==4){
        //     for (int i = 0; i < 4; i++)
        //     {
        //         if((cordSum-vec[i][0]-vec[i][1])%3==0){return true;}
        //     }
        //     return false;
        // }
        // else{
        //     for (int i = 0; i < 5; i++)
        //     {
        //         for (int j = i+1; j < 5; i++)
        //         {
                    
        //         }
                
        //     }
            
        // }
    }
public:
    bool validTicTacToe(vector<string>& board) {
        int countX = 0; int cordSumX = 0; vector<vector<int>> vecX;
        int countO = 0; int cordSumO = 0; vector<vector<int>> vecO;
        int spaceCount = 0;
        for(int i=0 ; i<3 ; i++){
            // cout<<board[i]<<endl;
            for(int j=0 ; j<3; j++){
                if(board[i][j]=='O'){
                    countO++;cordSumO+=(i+j);
                    vector<int> v(2);
                    v.push_back(i);v.push_back(j);
                    vecO.push_back(v);
                }
                else if(board[i][j]=='X'){
                    countX++;cordSumX+=(i+j);
                    vector<int> v(2);
                    v.push_back(i);v.push_back(j);
                    vecX.push_back(v);
                }
                else{spaceCount++;}
            }
            if((countX!=0)&&(countX-1!=countO)){return false;}
        }
    }
};
