#include<bits/stdc++.h>
using namespace std;


// my burte back tracking based solution (using stack)
// TC : O(3^N)
// SC : O(N + N) {one for recursion calls stack space and one for auxillary stack}


class Solution {
public:

    bool helper(string s , stack<char> st , int i , int n){

        if(i>=n) return true;

        while(i<n){

            if(s[i] == '('){
                st.push(s[i]);
            }

            else if(s[i]==')'){
                if(!st.empty()){
                    st.pop();
                }
                else{
                    return false;
                }
            }

            else{ // s[i] == '*'

                bool b1 , b2 , b3;

                // * = NULL
                b1 = helper(s,st,i+1,n);

                // * = '('
                st.push('(');
                b2 = helper(s,st,i+1,n);
                st.pop();

                // * = ')'
                if(!st.empty()){
                    st.pop();
                    b3 = helper(s,st,i+1,n);
                }
                else{
                    b3 = false;
                }

                return b1 || b2 || b3;

            }

            i++;

        }

        return true;

    }

    bool checkValidString(string s) {

        int n = s.size();
        stack<char> st;

        return helper(s , st , 0 , n);

    }
};



// ------------------------------------------------------------------ //

// striver's burte back tracking based clean solution (without stack)
// TC : O(3^N)
// SC : O(N)

class Solution {
public:

    bool helper(string s , int cnt , int i , int n){

        if(cnt<0) return false;

        // if(i>=n) return true;
        if(i>=n) return (cnt == 0);

        if(s[i] == '('){
            return helper(s , cnt+1 , i+1 , n);
        }

        else if(s[i]==')'){
            return helper(s , cnt-1 , i+1 , n);
        }

        else{ // s[i] == '*'
            return helper(s , cnt+1 , i+1 , n ) || helper(s , cnt-1 , i+1 , n ) || helper(s , cnt , i+1 , n ) ;
        }

        return true;

    }

    bool checkValidString(string s) {

        int n = s.size();
        int cnt = 0;

        return helper(s , cnt , 0 , n);

    }
};



// ------------------------------------------------------------------ //

// memorization solution

class Solution {
public:

    bool helper(string s , int cnt , int i , int n , vector<vector<int>>& memo){

        if(cnt<0) return false;

        // if(i>=n) return true;
        if(i>=n) return (cnt == 0);

        if( memo[cnt][i] != -1 ) return memo[cnt][i];

        if(s[i] == '('){
            return memo[cnt][i] = helper(s , cnt+1 , i+1 , n , memo );
        }

        else if(s[i]==')'){
            return memo[cnt][i] = helper(s , cnt-1 , i+1 , n , memo );
        }

        else{ // s[i] == '*'
            return memo[cnt][i] = helper(s , cnt+1 , i+1 , n , memo  ) || helper(s , cnt-1 , i+1 , n , memo  ) || helper(s , cnt , i+1 , n , memo  ) ;
        }

        return memo[cnt][i] = true;

    }

    bool checkValidString(string s) {

        int n = s.size();
        int cnt = 0;

        vector<vector<int>> memo(n+1,vector<int>(n+1 , -1));


        return helper(s , cnt , 0 , n , memo );

    }


};


// ------------------------------------------------------------------ //

// try 3


// class Solution {
// public:

//     bool checkValidString(string s) {

//         int n = s.size();
//         // stack<char> st;

//         // int l = 0 , r = n-1 ;

//         int sum = 0;

//         int i=0 ; 
//         int mini = 0 ;
//         int maxi = 0 ;
//         while (i<n){
//             if (s[i] == '(') sum++;
//             else if (s[i] == ')') sum--;
//             else {
//                 // s[i] == '*'
//                 mini--;
//                 maxi++;
//                 // or ignore
//             }

//             i++;

//         }        

//         // check if there exists an x belonging to range [mini , maxi] s.t. sum+x == 0
//         // i.e. find x = -sum in range


//         if( ( mini <= (-sum) ) && ( (-sum) <= maxi ) )
//             return true;

//         else return false;

//     }
// };


// same as striver's solution

class Solution {
public:

    bool checkValidString(string s) {

        int n = s.size();

        int i=0 ; 
        int mini = 0 ;
        int maxi = 0 ;
         
        while (i<n){
            if (s[i] == '(') {
                // sum++; 
                mini++; maxi++;
            }
            else if (s[i] == ')') {
                // sum--; 
                mini--; maxi--;
            }
            else {
                // s[i] == '*'
                mini--;
                maxi++;
                // or ignore
            }

            if(maxi < 0) return false;

            if(mini < 0) mini = 0;

            i++;

        }        

        return mini == 0;

    }
};