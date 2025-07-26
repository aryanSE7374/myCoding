#include<bits/stdc++.h>
using namespace std;

// chatGPT stack based solution

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int a : asteroids) {
            bool destroyed = false;

            while (!st.empty() && a < 0 && st.top() > 0) {
                if (abs(a) > st.top()) {
                    st.pop();  // Current asteroid destroys the one on stack
                } else if (abs(a) == st.top()) {
                    st.pop();  // Both destroy each other
                    destroyed = true;
                    break;
                } else {
                    destroyed = true;  // Current asteroid is destroyed
                    break;
                }
            }

            if (!destroyed) {
                st.push(a);
            }
        }

        // Convert stack to vector
        vector<int> result(st.size());
        for (int i = st.size() - 1; i >= 0; --i) {
            result[i] = st.top();
            st.pop();
        }

        return result;
    }
};

// ------------------------------------------------------------------------------------------------------------------------------------ // 

// striver's optimal solution

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        int n = asteroids.size();

        for (int i = 0; i < n; ++i) {
            if (asteroids[i] > 0) {
                st.push_back(asteroids[i]);
            } else {
                while (!st.empty() && st.back() > 0 && st.back() < abs(asteroids[i])) {
                    st.pop_back();
                }
                if (!st.empty() && st.back() == abs(asteroids[i])) {
                    st.pop_back();
                } else if (st.empty() || st.back() < 0) {
                    st.push_back(asteroids[i]);
                }
            }
        }
        return st;
    }
};

// ------------------------------------------------------------------------------------------------------------------------------------ // 

// above striver's sol modularized by GPT

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;

        for (int asteroid : asteroids) {
            if (asteroid > 0) {
                st.push_back(asteroid);  // Right-moving, no collision
            } else {
                handleCollision(st, asteroid);
            }
        }

        return st;
    }

private:
    void handleCollision(vector<int>& st, int asteroid) {
        while (!st.empty() && st.back() > 0 && st.back() < abs(asteroid)) {
            st.pop_back();  // Weaker right asteroid explodes
        }

        if (!st.empty() && st.back() == abs(asteroid)) {
            st.pop_back();  // Both explode
        } else if (st.empty() || st.back() < 0) {
            st.push_back(asteroid);  // Left asteroid survives
        }
        // Else: current asteroid explodes (not pushed)
    }
};


// ------------------------------------------------------------------------------------------------------------------------------------ // 