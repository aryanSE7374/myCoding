#include<bits/stdc++.h>
using namespace std;

// below is a vatiation of the sub-problem of #2

// check valid paranthesis sub problem

// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// 1. Open brackets must be closed by the same type of brackets.
// 2. Open brackets must be closed in the correct order.
// 3. Every close bracket has a corresponding open bracket of the same type.


// my try 1  : failed

// '(', ')' :- parantheses
// '{', '}' :- squres
// '[' , ']':- curlies

class Solution {
public:
    bool isValid(string s) {
        int parantheses = 0;
        int squares = 0; 
        int curlies = 0;
        for(char c : s){
            if(!parantheses && c=='(') parantheses++;
            else if(parantheses>0 &&  c==')') parantheses--;
            else if(!squares && c=='[') squares++;
            else if(squares>0 && c==']') squares--;
            else if(!curlies && c=='{') curlies++;
            else if(curlies>0 && c=='}') curlies--;
            else {
                return false;
            }
        }
        return true;
        // return (parantheses==0 && squares==0 && curlies==0);
    }
};

// input : s = "(][(][][}(((}}}"

