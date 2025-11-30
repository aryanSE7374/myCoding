#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {

        int f5 = 0;
        int f10 = 0;
        int f20 = 0;

        for(int bill : bills){
            if(bill == 5){
                f5++;
            }
            else if(bill == 10){
                f10++;
                if(f5>0){
                    f5--;
                }
                else{
                    return false;
                }
            }
            else{ // bill == 20
                f20++;
                if( (f5>0) && (f10>0) ){
                    f5--;
                    f10--;
                    f20++;
                }
                else if( f5 >= 3 ){
                    f5 -= 3;
                    f20++;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};