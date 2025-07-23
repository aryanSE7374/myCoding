#include<bits/stdc++.h>
using namespace std;

// kadane's algo : CTM

class Solution {
public:
    int maxSubArraySum(vector<int>& nums) {
        int maxi=INT_MIN , sum=0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum+=nums[i];
            if(sum>maxi){
                maxi = sum;
            }
            if(sum<0){
                sum=0;
            }
        }
        return maxi;
    }
};



// kadane's algo - follow up ques : 
// There might be more than one subarray with the maximum sum. We need to print any of them.


class Solution {
public:
    int maxSubArraySum(vector<int>& nums) {
        int maxi=INT_MIN , sum=0; int s_idxMax = 0; int end_idxMax = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            // int s_idx = i , end_idx=i;
            // while (i < nums.size() && sum>=0)
            // {
            //     sum+=nums[i];
            //     end_idx = i;
            //     if(sum>maxi){
            //         maxi = sum;
            //         s_idxMax = s_idx , end_idxMax = end_idx;
            //     }
            //     if(sum<0){
            //         sum=0;
            //         break;
            //     }
            //     i++;
            // }
            



            // handling redundant loops: 
            if (nums.empty()) {
            cout << "The array is empty." << endl;
            return 0;
            }

            int maxi = INT_MIN, sum = 0;
            int s_idxMax = -1, end_idxMax = -1;
            int tempStart = 0; // Temporary start index for the current subarray

            for (int i = 0; i < nums.size(); i++) {
                sum += nums[i];

                // Update maximum sum and indices
                if (sum > maxi) {
                    maxi = sum;
                    s_idxMax = tempStart;
                    end_idxMax = i;
                }

                // If sum becomes negative, reset it and update the temporary start index
                if (sum < 0) {
                    sum = 0;
                    tempStart = i + 1;
                }
            }

        }
        // Print the subarray with the maximum sum
        if (s_idxMax != -1 && end_idxMax != -1) {
            cout << "The subarray is: [";
            for (int i = s_idxMax; i <= end_idxMax; i++) {
                cout << nums[i];
                if (i != end_idxMax) cout << " ";
            }
            cout << "]" << endl;
        }

        return maxi;
    }
};




// striver's solution : 

long long maxSubarraySum(int arr[], int n) {
    long long maxi = LONG_MIN; // maximum sum
    long long sum = 0;

    int start = 0;
    int ansStart = -1, ansEnd = -1;
    for (int i = 0; i < n; i++) {

        if (sum == 0) start = i; // starting index

        sum += arr[i];

        if (sum > maxi) {
            maxi = sum;

            ansStart = start;
            ansEnd = i;
        }

        // If sum < 0: discard the sum calculated
        if (sum < 0) {
            sum = 0;
        }
    }

    //printing the subarray:
    cout << "The subarray is: [";
    for (int i = ansStart; i <= ansEnd; i++) {
        cout << arr[i] << " ";
    }
    cout << "]n";

    // To consider the sum of the empty subarray
    // uncomment the following check:

    //if (maxi < 0) maxi = 0;

    return maxi;
}
 

// gpt's optimization to the solution : 

long long maxSubarraySum(int arr[], int n) {
    if (n == 0) {
        cout << "The array is empty." << endl;
        return 0; // Handle empty array case
    }

    long long maxi = LONG_MIN; // Maximum sum
    long long sum = 0;

    int start = 0, ansStart = -1, ansEnd = -1;

    for (int i = 0; i < n; i++) {
        if (sum == 0) start = i; // Update starting index when sum resets to 0

        sum += arr[i];

        if (sum > maxi) {
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }

        // Reset sum if it becomes negative
        if (sum < 0) {
            sum = 0;
        }
    }

    // If no valid subarray was found
    if (ansStart == -1 || ansEnd == -1) {
        cout << "No valid subarray found." << endl;
        return 0;
    }

    // Printing the subarray:
    cout << "The subarray is: [";
    for (int i = ansStart; i <= ansEnd; i++) {
        cout << arr[i];
        if (i != ansEnd) cout << " "; // Avoid trailing space
    }
    cout << "]" << endl;

    return maxi;
}

int main(){
    return 0;
}