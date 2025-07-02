#include<bits/stdc++.h>
using namespace std;

// brute try
// TC : O(N
// SC : O(N)

class Solution {
  public:
    void Reverse(stack<int> &St) {
        stack<int> temp;
        while (!St.empty())
        {
            temp.push(St.top());
            St.pop();
        }
        while (!temp.empty())
        {
            St.push(temp.top());
            temp.pop();
        }
    }
};