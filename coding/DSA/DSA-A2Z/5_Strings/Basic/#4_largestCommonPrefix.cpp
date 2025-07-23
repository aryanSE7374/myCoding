#include<bits/stdc++.h>
using namespace std;

// Method 1: My Solution (Character-by-Character Matching) : best on leetcode
// Time Complexity: O(n * m), where n is the number of strings and m is the length of the shortest string
// Space Complexity: O(1)
class Solution1 {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        int chars = 0;
        string str = "";
        bool flag = true;
        for (int i = 0; flag && i <= 200; i++) {
            for (int j = 0; j < n; j++) {
                if ((strs[j].length() <= i) || (strs[j][i] != strs[0][i])) {
                    chars = i;
                    flag = false;
                    break;
                }
            }
        }
        for (int i = 0; i < chars; i++) {
            str += strs[0][i];
        }
        return str;
    }
};

// Method 2: Horizontal Scanning
// Time Complexity: O(n * m)
// Space Complexity: O(1)
class Solution2 {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        string prefix = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            while (strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.length() - 1);
                if (prefix.empty()) return "";
            }
        }
        return prefix;
    }
};

// Method 3: Vertical Scanning
// Time Complexity: O(n * m)
// Space Complexity: O(1)
class Solution3 {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        for (int i = 0; i < strs[0].length(); i++) {
            char ch = strs[0][i];
            for (int j = 1; j < strs.size(); j++) {
                if (i >= strs[j].length() || strs[j][i] != ch) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};

// Method 4: Divide and Conquer
// Time Complexity: O(n * m)
// Space Complexity: O(log n) (recursion stack)
class Solution4 {
private:
    string commonPrefix(string left, string right) {
        int minLength = min(left.length(), right.length());
        for (int i = 0; i < minLength; i++) {
            if (left[i] != right[i]) {
                return left.substr(0, i);
            }
        }
        return left.substr(0, minLength);
    }

    string divideAndConquer(vector<string>& strs, int l, int r) {
        if (l == r) {
            return strs[l];
        }
        int mid = (l + r) / 2;
        string left = divideAndConquer(strs, l, mid);
        string right = divideAndConquer(strs, mid + 1, r);
        return commonPrefix(left, right);
    }

public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        return divideAndConquer(strs, 0, strs.size() - 1);
    }
};

// Method 5: Binary Search
// Time Complexity: O(n * log m), where m is the length of the shortest string
// Space Complexity: O(1)
class Solution5 {
private:
    bool isCommonPrefix(vector<string>& strs, int length) {
        string prefix = strs[0].substr(0, length);
        for (int i = 1; i < strs.size(); i++) {
            if (strs[i].find(prefix) != 0) {
                return false;
            }
        }
        return true;
    }

public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        int minLen = INT_MAX;
        for (const string& str : strs) {
            minLen = min(minLen, (int)str.length());
        }

        int low = 1, high = minLen;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (isCommonPrefix(strs, mid)) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return strs[0].substr(0, (low + high) / 2);
    }
};


int main() {
    vector<string> strs = {"flower", "flow", "flight"};
    
    Solution1 sol1;
    cout << "Your Solution: " << sol1.longestCommonPrefix(strs) << endl;

    Solution2 sol2;
    cout << "Horizontal Scanning: " << sol2.longestCommonPrefix(strs) << endl;

    Solution3 sol3;
    cout << "Vertical Scanning: " << sol3.longestCommonPrefix(strs) << endl;

    Solution4 sol4;
    cout << "Divide and Conquer: " << sol4.longestCommonPrefix(strs) << endl;

    Solution5 sol5;
    cout << "Binary Search: " << sol5.longestCommonPrefix(strs) << endl;

    return 0;
}