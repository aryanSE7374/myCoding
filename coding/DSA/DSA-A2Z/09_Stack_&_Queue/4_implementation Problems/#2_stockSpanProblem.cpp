#include<bits/stdc++.h>
using namespace std;



// brute

// Time: O(n) per call to next() in worst case
// Space: O(n) to store all prices


class StockSpanner {
private:
    vector<int> prices;
    int ind;

public:
    StockSpanner() {
        ind = -1;
    }

    int next(int price) {
        prices.push_back(price);
        int i = prices.size() - 1;
        int span = 1;
        while (--i >= 0 && prices[i] <= price) {
            span++;
        }
        return span;
    }

};


// ------------------------------------------------------------------------------------------------------------------------------------ // 

// striver's sol
// Time: O(1) amortized per call to next()
// Space: O(n) for stack storing all prices and indices

class StockSpanner {
private:
    stack<pair<int, int>> st; // {price, index}
    int ind;

public:
    StockSpanner() {
        ind = -1;
    }

    int next(int price) {
        ind++;

        while (!st.empty() && st.top().first <= price) {
            st.pop();
        }

        int ans;
        if (st.empty()) {
            ans = ind - (-1); // All previous prices <= current
        } else {
            ans = ind - st.top().second;
        }

        st.push({price, ind});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */


// ------------------------------------------------------------------------------------------------------------------------------------ // 

// chatGPT sol
// Time: O(1) amortized per call to next()
// Space: O(n) for stack storing all prices

class StockSpanner {
private:
    stack<pair<int, int>> st; // {price, span}
    
public:
    StockSpanner() {}

    int next(int price) {
        int span = 1;
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }
        st.push({price, span});
        return span;
    }
};