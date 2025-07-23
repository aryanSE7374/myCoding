#include<bits/stdc++.h>
using namespace std;

// brute

/*
⏱️ Time Complexity:
	•	push, pop, top → O(1)
	•	getMin → ❌ O(N)

❌ Weakness:
	•	getMin() is not O(1) → violates constraint.
	•	Extra time on each min query.
*/

class MinStack {
    stack<int> st;
public:
    void push(int val) {
        st.push(val);
    }

    void pop() {
        st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        int minVal = INT_MAX;
        stack<int> temp = st;
        while (!temp.empty()) {
            minVal = min(minVal, temp.top());
            temp.pop();
        }
        return minVal;
    }
};

// ------------------------------------------------------------------------------------------------------------------------------------ // 

/*
2. 🧠 Better Approach

Idea:

Use two stacks:
	•	mainStack: stores all values.
	•	minStack: stores the minimum up to that point.

Push into minStack only if current value is smaller or equal to top of minStack.
*/

class MinStack {
    stack<int> mainStack;
    stack<int> minStack;

public:
    void push(int val) {
        mainStack.push(val);
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }

    void pop() {
        if (mainStack.top() == minStack.top()) {
            minStack.pop();
        }
        mainStack.pop();
    }

    int top() {
        return mainStack.top();
    }

    int getMin() {
        return minStack.top();
    }
};

// ------------------------------------------------------------------------------------------------------------------------------------ // 

// better implementation 2 : using stack of pairs of int,int

class MinStack {
    stack<pair<int, int>> st;

public:
    void push(int val) {
        int currMin = st.empty() ? val : min(val, st.top().second);
        st.push({val, currMin});
    }

    void pop() {
        st.pop();
    }

    int top() {
        return st.top().first;
    }

    int getMin() {
        return st.top().second;
    }
};


// ------------------------------------------------------------------------------------------------------------------------------------ // 

/*
⚡ Optimal Variant (Optimized Space)

Core Idea (Encoding/Decoding Technique):

We use a single stack<long long> st and a minVal variable to keep track of the current minimum.

When a new minimum is pushed, we store a special encoded value instead of the actual number.


This encoding allows us to:
	•	Track the current minimum
	•	Recover the previous minimum when popping


encoding formula : encoded_value = 2 * val - minVal;

push()

how : 
we know that we only need to update the varibale under a constraint : 
    => val < minVal
    => val - minVal < 0
    => val - minVal + val < 0 + val
    => 2*val - minval < val 
    the encoded_value = 2*val - minval , which is gauranteed to be less than val and hence less than minVal
    so we will push this encoded value into the stack 
    now push the encoded_value on to the stack and update the minval with val so that it stores the actual element 

// ------------------------------------------------------------------------------------------------------------------------------------ // 

pop()

if(st.top < minval) => minVal is on top , popping will lose the track of minval encoded value

so we decode the minVal with the prev min Val using formula :
    minVal = 2 * val - encoded_value; {where encoded_value = st.top() , val = minval}


// ------------------------------------------------------------------------------------------------------------------------------------ // 

top()

if(st.top < minval) => minVal is on top , top will not give the actual value , it will give the encoded_value
    so to get rid off that , send the minVal (the actual val)

// ------------------------------------------------------------------------------------------------------------------------------------ // 

*/


class MinStack {
    stack<long long> st;
    long long minVal;

public:
    void push(int val) {
        if (st.empty()) {
            minVal = val;
            st.push(val);
        } else {
            if (val < minVal) {
                st.push(2LL * val - minVal);  // Encode
                minVal = val;
            } else {
                st.push(val);
            }
        }
    }

    void pop() {
        if (st.top() < minVal) {
            minVal = 2 * minVal - st.top();  // Decode previous min
        }
        st.pop();
    }

    int top() {
        if (st.top() < minVal)
            return minVal; // Encoded value
        else
            return st.top();
    }

    int getMin() {
        return minVal;
    }
};

// ------------------------------------------------------------------------------------------------------------------------------------ // 