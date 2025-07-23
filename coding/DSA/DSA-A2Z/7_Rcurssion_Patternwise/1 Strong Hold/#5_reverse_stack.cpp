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
        St = temp;
    }
};

// recursive
// Recursion plus a second stack ⇒ O(N) extra space.
// TC : O(N)
// SC : O(N)

class Solution {
  public:
    void rev(stack<int> &St , stack<int> &temp){
        if(St.empty()){
            return;
        }
        temp.push(St.top());
        St.pop();
        rev(St , temp);
    }
    void Reverse(stack<int> &St) {
        stack<int> temp;
        rev(St , temp);
        St=temp;
    }
};

// chatGPT optimal approach
// using Insert at Bottom logic

// Time: O(N²) (worst-case)
// Auxiliary space: No extra containers (O(1) by problem definition).
// Only the implicit recursion frames (O(N) call-stack), which the judge allows.


class Solution {
public:
    // helper: insert x at BOTTOM of stack using recursion only
    void insertAtBottom(stack<int>& st, int x) {
        if (st.empty()) {          // base: reached bottom
            st.push(x);
            return;
        }
        int top = st.top(); st.pop();
        insertAtBottom(st, x);     // go deeper
        st.push(top);              // restore
    }

    // main reverse
    void Reverse(stack<int>& St) {
        if (St.empty()) return;    // base

        int top = St.top();
        St.pop();

        Reverse(St);               // reverse the rest
        insertAtBottom(St, top);   // put current at bottom
    }
};