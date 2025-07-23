#include<bits/stdc++.h>
using namespace std;


// this is a sample comment

/*
// wrong approach

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int l = nums.size()-2;
        int r=l+1;
        while(l>=0 && r>=0){
            if(nums[l]<nums[r]){
                int minIdx = r;
                while(r<nums.size()){
                    if (nums[r]>nums[l] && nums[r]<nums[minIdx])
                    {
                        minIdx = r;
                    }
                    r++;
                }
                swap(nums[l] , nums[minIdx]);
                break;
            }
            l--; r--;
        }
        sort(nums.begin()+l+1 , nums.end());
    }
};

*/


//----------------------------------------------------------------------------------


/*
Brute Force: Finding all possible permutations. 

// extreme brute

Explanation:
	1.	Generate all permutations:
The do-while loop with next_permutation generates all possible permutations of the input array, starting from the smallest permutation.
	2.	Sort and find:
The permutations are already generated in lexicographical order because of the way next_permutation works.
	3.	Identify the next permutation:
Locate the input array in the list and assign the next one to nums. If it’s the last permutation, wrap around to the first.

Complexity:
	•	Time Complexity: O(N! \times N)
N! for generating all permutations, and N for comparing arrays in each iteration.
	•	Space Complexity: O(N! \times N)
Space for storing all permutations.

This method is highly inefficient but adheres to the brute-force logic you requested.

// implementation
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        vector<vector<int>> permutations;
        
        // Step 1: Generate all permutations
        sort(nums.begin(), nums.end()); // Start with the smallest permutation
        do {
            permutations.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        
        // Step 2: Find the input array in the sorted list
        for (int i = 0; i < permutations.size(); i++) {
            if (permutations[i] == nums) {
                // Step 3: Return the next permutation or the first one if no next exists
                if (i + 1 < permutations.size()) {
                    nums = permutations[i + 1];
                } else {
                    nums = permutations[0]; // Wrap around to the first permutation
                }
                return;
            }
        }
    }
};


Approach :

Step 1: Find all possible permutations of elements present and store them.

Step 2: Search input from all possible permutations.

Step 3: Print the next permutation present right after it.

Complexity Analysis
For finding, all possible permutations, it is taking N!xN. N represents the number of elements present in the input array. 
Also for searching input arrays from all possible permutations will take N!. Therefore, it has a Time complexity of O(N!xN).

Space Complexity :
Since we are not using any extra spaces except stack spaces for recursion calls. So, it has a space complexity of O(1).


// brute implementation
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        vector<int> original = nums; // Keep a copy of the original array
        
        // Sort the array to start with the smallest permutation
        sort(nums.begin(), nums.end());
        
        do {
            if (nums == original) {
                // Generate the next permutation
                if (next_permutation(nums.begin(), nums.end())) {
                    return; // Found the next permutation
                } else {
                    // If no next permutation exists, reset to the smallest permutation
                    sort(nums.begin(), nums.end());
                    return;
                }
            }
        } while (next_permutation(nums.begin(), nums.end()));
    }
};


*/



//----------------------------------------------------------------------------------

/*
sol2  : better
Using in-built function

C++ provides an in-built function called next_permutation() which directly returns the lexicographically next greater permutation of the input.

next_permutation(arr,arr+n); // n = arr.size() 
next_permutation(nums.begin(), nums.end()) // vectors

*/

//----------------------------------------------------------------------------------


// optimal striver

class striverSol{

    vector<int> nextGreaterPermutation(vector<int> &A) {
        int n = A.size(); // size of the array.

        // Step 1: Find the break point:
        int ind = -1; // break point
        for (int i = n - 2; i >= 0; i--) {
            if (A[i] < A[i + 1]) {
                // index i is the break point
                ind = i;
                break;
            }
        }

        // If break point does not exist:
        if (ind == -1) {
            // reverse the whole array:
            reverse(A.begin(), A.end());
            return A;
        }

        // Step 2: Find the next greater element
        //         and swap it with arr[ind]:

        for (int i = n - 1; i > ind; i--) {
            if (A[i] > A[ind]) {
                swap(A[i], A[ind]);
                break;
            }
        }

        // Step 3: reverse the right half:
        reverse(A.begin() + ind + 1, A.end());

        return A;
    }

};

//----------------------------------------------------------------------------------

// optimal (GPT)

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n = nums.size();
        int l = n - 2;
        // Step 1: Find the first decreasing element from the right
        while (l >= 0 && nums[l] >= nums[l + 1]) {
            l--;
        }

        if (l >= 0) {
            // Step 2: Find the smallest element greater than nums[l] to the right
            int r = n - 1;
            while (nums[r] <= nums[l]) {
                r--;
            }
            // Swap nums[l] and nums[r]
            swap(nums[l], nums[r]);
        }

        // Step 3: Reverse the elements to the right of index l
        reverse(nums.begin() + l + 1, nums.end());
    }
};
