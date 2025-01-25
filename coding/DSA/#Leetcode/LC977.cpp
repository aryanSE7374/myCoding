#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        int l = 0, r = n - 1;
        
        while (l < n && nums[l] < 0) { //searching for 1st positive integer
            l++;
        }
        while (r >= 0 && nums[r] > 0) { //searching for 1st negative integer
            r--;
        }
        
        int zeroes = r - l + 1; // number of zeroes
        int i = 0;
        for (; i < (r - l + 1); i++) {
            res[i] = 0;
        }
        
        l--; r++; //go back to the last negative and frst positive integer

        while (l >= 0 && r < n) {
            if (nums[l]*nums[l] > nums[r]*nums[r]) {
                res[i] = nums[r]*nums[r];
                i++; r++;
            } else {
                res[i] = nums[l]*nums[l];
                i++; l--;
            }
        }
        while (l >= 0) { //if r exceeds the limit frst
            res[i] = nums[l]*nums[l];
            l--; i++;
        }
        while (r < n) { //if l exceeds the limit frst
            res[i] = nums[r]*nums[r];
            r++; i++;
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {-4, -1, 0, 3, 10};
    vector<int> result = solution.sortedSquares(nums);
    
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    int t;
    cin >> t;
    while (t-- > 0) {
        string str;
        cin >> str;
        if (str.length() <= 10) {
            cout << str << endl;
        } else {
            cout << str[0] << str.length() - 2 << str[str.length() - 1] << endl;
        }
    }
    
    return 0;
}
