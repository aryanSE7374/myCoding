#include<bits/stdc++.h>
using namespace std;

// editorial soln
// class Solution {
// public:
//     int reverse(int x) {
//         int rev = 0;
//         while (x != 0) {
//             int pop = x % 10;
//             x /= 10;
//             if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7))
//                 return 0;
//             if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8))
//                 return 0;
//             rev = rev * 10 + pop;
//         }
//         return rev;
//     }
// };


class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while(x!=0){
            int mod = x%10;
            x/=10;
            if((rev>INT_MAX/10) || (rev==INT_MAX/10)&&(mod>7)){
                return 0;
            }
            else if((rev<INT_MIN/10) || (rev==INT_MIN/10)&&(mod<-8)){
                return 0;
            }
            rev = rev*10 + mod;
        }
        return rev;
    }
};

int main()
{

    // cout<<-123%10<<endl;
    cout<<(int)'0'<<endl;
    
    // int num = 917824;
    // cout<<"original number : "<<num<<endl;
    // string str = "";
    // while (num>0)
    // {
    //     str+= char(num%10+48);
    //     num/=10;
    // }

    // cout<<str<<endl;

    return 0;
}

/*
Line 11: Char 23: runtime error: signed integer overflow: 246384741 * 10 cannot be represented in type 'int' (solution.cpp)
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior prog_joined.cpp:20:23
*/

