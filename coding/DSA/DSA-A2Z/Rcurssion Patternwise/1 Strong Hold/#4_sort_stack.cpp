#include<bits/stdc++.h>
using namespace std;


// brute sol : 

/*
store the elements of stack into an array or a vector , and the sort it
that would take O(N*logN) time and O(N) space
*/


// brute try

class Solution
{
public:
    void sortStack(stack<int> s){
        vector<int> vec;
        while (!s.empty())
        {
            vec.push_back(s.top());
            s.pop();
        }
        sort(vec.begin() , vec.end());
        for(int num : vec){
            s.push(num);
        }
    }
};

/*----------------------------------------------------------*/

// The structure of the class is
class SortedStack{
public:
    stack<int> s;
    void sort();
};

/*----------------------------------------------------------*/

// brute solution

/* The below method sorts the stack s
you are required to complete the below method */

void SortedStack::sort() {
    std::vector<int> v;

    // Step 1: Move elements to vector
    while (!s.empty()) {
        v.push_back(s.top());
        s.pop();
    }

    // Step 2: Sort in descending order (greatest to smallest)
    std::sort(v.begin(), v.end());

    // Step 3: Push back into stack
    for (int i = 0; i < v.size(); ++i) {
        s.push(v[i]); // greatest ends up on top
    }
}

/*----------------------------------------------------------*/

// optimal (recursive)

/* The below method sorts the stack s
you are required to complete the below method */

static void sortedInsert(std::stack<int>& s, int num) {
    // ascending: keep greatest on top
    if (s.empty() || s.top() <= num) {
        s.push(num);
        return;
    }
    int top = s.top();
    s.pop();
    sortedInsert(s, num);
    s.push(top);
}

void SortedStack::sort() {
    if (s.empty()) return;
    int top = s.top();
    s.pop();
    sort();
    sortedInsert(s, top);
}



/*----------------------------------------------------------*/


// implementation #2

/*----------------------------------------------------------
   File-local helpers inside an anonymous namespace
   → internal linkage (no global symbol collisions)
  ----------------------------------------------------------*/
namespace {                    // start unnamed namespace
    // Inserts `num` so the stack ends up **ascending**
    // (smallest element on TOP, largest at BOTTOM)
    void sortedInsertn(std::stack<int>& s, int num) {
        if (s.empty() || s.top() <= num) {   // correct place found
            s.push(num);
            return;
        }
        int top = s.top();
        s.pop();
        sortedInsertn(s, num);                // recurse deeper
        s.push(top);                         // restore popped item
    }
} // end unnamed namespace

/*----------------------------------------------------------
   SortedStack class using the helper above
  ----------------------------------------------------------*/
class SortedStack {
public:
    std::stack<int> s;

    // Recursively sorts the stack in **ascending order**:
    // top -> smallest ... bottom -> largest
    void sort() {
        if (s.empty()) return;               // base case

        int top = s.top();
        s.pop();

        sort();                              // sort remaining N-1
        sortedInsertn(s, top);                // insert current element
    }
};