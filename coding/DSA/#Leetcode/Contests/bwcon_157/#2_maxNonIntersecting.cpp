#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubstrings(string word) {
        int n = word.length();
        vector<int> firstOcc(26, -1), lastOcc(26, -1);
        // storing first and last occurrences of each character
        for (int i = 0; i < n; i++) {
            if (firstOcc[word[i] - 'a'] == -1) {
                firstOcc[word[i] - 'a'] = i;
            }
            lastOcc[word[i] - 'a'] = i;
        }
        vector<pair<int, int>> validIntervals;
        // Generating all the valid intervals
        for (int i = 0; i < 26; i++) {
            if (firstOcc[i] != -1 && lastOcc[i] - firstOcc[i] + 1 >= 4) {
                validIntervals.emplace_back(firstOcc[i], lastOcc[i]);
            }
        }
        // Sorting intervals by their ending position
        sort(validIntervals.begin(), validIntervals.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
        });
        // selection of intervals that are non-overlapping
        int count = 0, lastEnd = -1;
        for (const auto& interval : validIntervals) {
            if (interval.first > lastEnd) {
                count++;
                lastEnd = interval.second;
            }
        }
        return count;
    }
};


// try 2

class Solution {
public:
    int maxSubstrings(string word) {
        int n = word.length();
        vector<int> firstOcc(26, -1), lastOcc(26, -1);
        // storing first and last occurrences of each character
        for (int i = 0; i < n; i++) {
            if (firstOcc[word[i] - 'a'] == -1) {
                firstOcc[word[i] - 'a'] = i;
            }
            lastOcc[word[i] - 'a'] = i;
        }
        vector<pair<int, int>> validIntervals;
        // Generating all the valid intervals
        for (int i = 0; i < 26; i++) {
            if (firstOcc[i] != -1 && lastOcc[i] - firstOcc[i] + 1 >= 4) {
                int start = firstOcc[i], end = lastOcc[i];
                for (int j = start; j <= end; j++) {
                    end = max(end, lastOcc[word[j] - 'a']);
                }
                validIntervals.emplace_back(start, end);
            }
        }
        // Merging intervals if overlapping
        sort(validIntervals.begin(), validIntervals.end());
        vector<pair<int, int>> mergedIntervals;
        for (const auto& interval : validIntervals) {
            if (mergedIntervals.empty() || mergedIntervals.back().second < interval.first) {
                mergedIntervals.push_back(interval);
            } else {
                mergedIntervals.back().second = max(mergedIntervals.back().second, interval.second);
            }
        }
        // Counting intervals that are non-overlapping and satisfy the conditions
        int count = 0, lastEnd = -1;
        for (const auto& interval : mergedIntervals) {
            if (interval.first > lastEnd) {
                count++;
                lastEnd = interval.second;
            }
        }
        return count;
    }
};


// try 3

class Solution {
public:
    int maxSubstrings(string word) {
        int n = word.length();
        vector<int> firstOcc(26, -1), lastOcc(26, -1);
        // storing first and last occurrences of each character
        for (int i = 0; i < n; i++) {
            if (firstOcc[word[i] - 'a'] == -1) {
                firstOcc[word[i] - 'a'] = i;
            }
            lastOcc[word[i] - 'a'] = i;
        }
        vector<pair<int, int>> validIntervals;
        // Generating all the valid intervals
        for (int i = 0; i < 26; i++) {
            if (firstOcc[i] != -1 && lastOcc[i] - firstOcc[i] + 1 >= 4) {
                int start = firstOcc[i], end = lastOcc[i];
                bool valid = true;
                for (int j = start; j <= end; j++) {
                    if (firstOcc[word[j] - 'a'] < start || lastOcc[word[j] - 'a'] > end) {
                        valid = false;
                        break;
                    }
                }
                if (valid) {
                    validIntervals.emplace_back(start, end);
                }
            }
        }
        // Sorting intervals by their ending position
        sort(validIntervals.begin(), validIntervals.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
        });
        // selection of intervals that are non-overlapping
        int count = 0, lastEnd = -1;
        for (const auto& interval : validIntervals) {
            if (interval.first > lastEnd) {
                count++;
                lastEnd = interval.second;
            }
        }
        return count;
    }
};


// #3 wale ak solution

