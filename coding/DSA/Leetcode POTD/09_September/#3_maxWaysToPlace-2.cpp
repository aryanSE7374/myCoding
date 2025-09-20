#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-the-number-of-ways-to-place-people-ii/description/

// gemini pro optimal solution : ways to place 2

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        // 1. Sort by x-coordinate ascending, then y-coordinate descending
        sort(points.begin(), points.end(), [](const auto& a, const auto& b) {
            if (a[0] != b[0]) {
                return a[0] < b[0];
            }
            return a[1] > b[1];
        });

        int n = points.size();
        int count = 0;

        // 2. Iterate through each point as a potential dominator
        for (int i = 0; i < n; ++i) {
            int xi = points[i][0];
            int yi = points[i][1];
            
            // This will track the highest y-value of a point dominated by P_i found so far
            int max_dominated_y = INT_MIN; // Constraints: y >= 0

            // 3. Iterate through subsequent points as potential dominated points
            for (int j = i + 1; j < n; ++j) {
                int xj = points[j][0];
                int yj = points[j][1];

                // Check if P_i dominates P_j
                if (yi >= yj) {
                    // To be a valid pair, yj must be higher than any other
                    // point dominated by P_i that we've already seen.
                    // If not, that previous point would be inside the bounding box.
                    if (yj > max_dominated_y) {
                        count++;
                    }
                    // Update max_dominated_y with the highest valid y we've seen
                    max_dominated_y = max(max_dominated_y, yj);
                }
            }
        }

        return count;
    }
};