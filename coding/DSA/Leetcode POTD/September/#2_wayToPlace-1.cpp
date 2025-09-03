#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-the-number-of-ways-to-place-people-i/description/

// sol 1

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {

        int n = points.size();
        int count = 0;

        for(int i=0 ; i<n-1 ; i++){
            for (int j = i+1; j < n; j++)
            {
                int xa = points[i][0] , ya = points[i][1];
                int xb = points[j][0] , yb = points[j][1];

                if((xa <= xb && ya >= yb) || (xb <= xa && yb >= ya)){
                    bool flag = true;
                    for(int k=0 ; k<n ; k++){
                        if(k==i || k==j){continue;}
                        int xc = points[k][0] , yc = points[k][1];

                        int x1 = min(xa, xb), x2 = max(xa, xb);
                        int y1 = min(ya, yb), y2 = max(ya, yb);

                        // if( ( (xa < xc) && (xc < xb) ) && ( (yb < yc) && (yc < ya) )){
                        //     flag = false;
                        //     break;
                        // }
                        if (x1 <= xc && xc <= x2 && y1 <= yc && yc <= y2) {
                            flag = false;
                            break;
                        }
                    }
                    if(flag){
                        count++;
                    }
                }
            }
        }

        return count;
    }
};


// sol 2

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {

        int n = points.size();
        int count = 0;

        for(int i=0 ; i<n-1 ; i++){
            for (int j = i+1; j < n; j++)
            {
                int xa = points[i][0] , ya = points[i][1];
                int xb = points[j][0] , yb = points[j][1];

                if((xa <= xb && ya >= yb) || (xb <= xa && yb >= ya)){
                    bool flag = true;
                    for(int k=0 ; k<n ; k++){
                        if(k==i || k==j){continue;}
                        int xc = points[k][0] , yc = points[k][1];

                        // int x1 = min(xa, xb), x2 = max(xa, xb);
                        // int y1 = min(ya, yb), y2 = max(ya, yb);

                        if( ( ( (xa <= xc) && (xc <= xb) ) && ( (yb <= yc) && (yc <= ya)) )  ||
                            ( ( (xb <= xc) && (xc <= xa) ) && ( (ya <= yc) && (yc <= yb)) )
                        ){
                            flag = false;
                            break;
                        }
                    }
                    if(flag){
                        count++;
                    }
                }
            }
        }

        return count;
    }
};


// optimal try 1 : failed!

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        
        int n = points.size();
        sort(points.begin() , points.end());

        int count = 0;

        for(int i=1 ; i<n ; i++){
            for (int j = 0; j < i; j++)
            {
                int xa = points[i][0] , ya = points[i][1];
                int xb = points[j][0] , yb = points[j][1];

                if((xa <= xb && ya >= yb) || (xb <= xa && yb >= ya)){
                    bool flag = true;
                    for(int k=0 ; k<i ; k++){
                        if(k==j){continue;}
                        int xc = points[k][0] , yc = points[k][1];

                        if( ( ( (xa <= xc) && (xc <= xb) ) && ( (yb <= yc) && (yc <= ya)) )  ||
                            ( ( (xb <= xc) && (xc <= xa) ) && ( (ya <= yc) && (yc <= yb)) )
                        ){
                            flag = false;
                            break;
                        }
                    }
                    if(flag){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};


// gemini pro optimal solution : ways to place 2 (use : INT_MIN for maxdominated)


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
            int max_dominated_y = -1; // Constraints: y >= 0

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