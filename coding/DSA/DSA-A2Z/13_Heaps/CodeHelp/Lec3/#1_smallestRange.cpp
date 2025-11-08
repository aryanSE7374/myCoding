#include<bits/stdc++.h>
using namespace std;

// brute solution

// TC : O((maxi-mini+1)^2 * n * k) ; k = nums.length , n = nums[i].length
// SC : O(1)

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {

        int mini = INT_MAX;
        int maxi = INT_MIN;

        for (auto &vec : nums) {
            mini = min(mini, vec.front());
            maxi = max(maxi, vec.back());
        }

        // for(all ranges form mini to maxi , check which range is good and store if len<min len)
    

        int bestL = mini, bestR = maxi;
        int bestLen = maxi - mini;

        // Try every possible range [L, R]
        for (int L = mini; L <= maxi; L++) {
            for (int R = L; R <= maxi; R++) {

                bool valid = true;
                for (auto &list : nums) {
                    // Check if this list has at least one element in [L, R]
                    bool found = false;
                    for (int x : list) {
                        if (x >= L && x <= R) {
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        valid = false;
                        break;
                    }
                }

                if (valid && (R - L < bestLen)) {
                    bestLen = R - L;
                    bestL = L;
                    bestR = R;
                }
            }
        }

        return {bestL, bestR};


    }
};


// ------------------------------------------------------------------------------------------------ //

// better approach - 1 (TLE)
// TC : O(n * k^2)
// SC : O(k)



class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {

        int k = nums.size();
        vector<int> ptr(k, 0); // pointers for each list
        
        int rangeStart = 0, rangeEnd = INT_MAX;
        bool flag = true;

        while (flag) {
            int minVal = INT_MAX, maxVal = INT_MIN;
            int minIndex = -1;

            // Step 1: find current min and max
            for (int i = 0; i < k; i++) {
                int val = nums[i][ptr[i]];
                if (val < minVal) {
                    minVal = val;
                    minIndex = i;
                }
                maxVal = max(maxVal, val);
            }

            // Step 2: update best range if smaller
            if (maxVal - minVal < rangeEnd - rangeStart) {
                rangeStart = minVal;
                rangeEnd = maxVal;
            }

            // Step 3: move pointer for the list that had min element
            ptr[minIndex]++;

            // Step 4: if that list is exhausted → stop
            if (ptr[minIndex] == nums[minIndex].size()) {
                flag = false;
            }
        }

        return {rangeStart, rangeEnd};
        
    }
};



// ------------------------------------------------------------------------------------------------ //

// optimal approach - 1 : Sliding window based (accepted)

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {

        vector<pair<int,int>> merged; // {value, list_index}

        for (int i = 0; i < nums.size(); i++) {
            for (int val : nums[i])
                merged.push_back({val, i});
        }

        sort(merged.begin(), merged.end()); // sort by value

        unordered_map<int,int> freq; // count of lists covered
        int covered = 0;
        int totalLists = nums.size();

        int left = 0;
        int bestL = merged[0].first, bestR = merged.back().first;
        for (int right = 0; right < merged.size(); right++) {
            int listIdx = merged[right].second;
            freq[listIdx]++;
            if (freq[listIdx] == 1) covered++;

            // try to shrink
            while (covered == totalLists) {
                int Lval = merged[left].first;
                int Rval = merged[right].first;
                if (Rval - Lval < bestR - bestL) {
                    bestL = Lval;
                    bestR = Rval;
                }

                // move left forward
                int leftList = merged[left].second;
                freq[leftList]--;
                if (freq[leftList] == 0) covered--;
                left++;
            }
        }

        return {bestL, bestR};
    }
};



// ------------------------------------------------------------------------------------------------ //

// optimal approach - 2 (using heap)
// TC : O()
// SC : O()

class Solution {
public:
    struct Node {
        int data;
        int row;
        int col;
        Node(int d, int r, int c) : data(d), row(r), col(c) {}
    };

    struct Compare {
        bool operator()(Node* a, Node* b) {
            return a->data > b->data;  // min-heap based on data
        }
    };

    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size(); // number of lists
        int mini = INT_MAX, maxi = INT_MIN;

        // Min-heap to store {value, row, col}
        priority_queue<Node*, vector<Node*>, Compare> pq;

        // Step 1️: Push first element of each list
        for (int i = 0; i < k; i++) {
            int element = nums[i][0];
            maxi = max(maxi, element);
            mini = min(mini, element);
            pq.push(new Node(element, i, 0));
        }

        int start = mini, end = maxi;

        // Step 2️: Process the heap
        while (!pq.empty()) {
            Node* temp = pq.top();
            pq.pop();

            mini = temp->data; // smallest element (current min)

            // Update range if smaller
            if (maxi - mini < end - start) {
                start = mini;
                end = maxi;
            }

            // Step 3️: Push next element from same list
            if (temp->col + 1 < nums[temp->row].size()) {
                int nextVal = nums[temp->row][temp->col + 1];
                maxi = max(maxi, nextVal);
                pq.push(new Node(nextVal, temp->row, temp->col + 1));
            } else {
                // One of the lists is exhausted → stop
                break;
            }
        }

        return {start, end};
    }
};
// ------------------------------------------------------------------------------------------------ //

// chatGPT version

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();

        // Min-heap to store {value, list_index, element_index}
        using Node = tuple<int, int, int>; 
        priority_queue<Node, vector<Node>, greater<Node>> minHeap;

        int currentMax = INT_MIN; // tracks current max among elements in heap

        // Step 1️⃣: push the first element of each list
        for (int i = 0; i < k; i++) {
            minHeap.push({nums[i][0], i, 0});
            currentMax = max(currentMax, nums[i][0]);
        }

        // Step 2️⃣: track the best (smallest) range
        int rangeStart = 0, rangeEnd = INT_MAX;

        while (true) {
            auto [val, listIdx, elemIdx] = minHeap.top();
            minHeap.pop();

            // Update best range
            if (currentMax - val < rangeEnd - rangeStart) {
                rangeStart = val;
                rangeEnd = currentMax;
            }

            // Step 3️⃣: Move ahead in the same list
            if (elemIdx + 1 == nums[listIdx].size()) break; // exhausted one list

            int nextVal = nums[listIdx][elemIdx + 1];
            minHeap.push({nextVal, listIdx, elemIdx + 1});
            currentMax = max(currentMax, nextVal);
        }

        return {rangeStart, rangeEnd};

    }
};


// ------------------------------------------------------------------------------------------------ //

