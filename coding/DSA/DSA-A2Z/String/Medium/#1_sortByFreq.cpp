#include<bits/stdc++.h>
using namespace std;

// my brute try : better than brute
/*
Overall Time Complexity:
	•	Frequency Count: O(n)
	•	Sorting: O(m*log m)
	•	Building the Result: O(n)

Thus, the total complexity is O(n + m*log m), which is efficient for this problem.

Space complexity : map = O(n) , res string = O(n) , vector = O(n)
SC : O(n)

*/

class Solution {
public:
    string frequencySort(string s) {
        string res = "";
        unordered_map<char , int> mpp;
        for(char c : s){
            mpp[c]++;
        }
        vector<pair<char, int>> vec(mpp.begin(), mpp.end());
        // Sort the vector by the second element (value) in ascending order
        sort(vec.begin(), vec.end(), [](const auto &a, const auto &b) {
            return a.second > b.second; // For ascending, use `a.second < b.second`
        });
        for(auto it : vec){
            // for(int i=0 ; i<it.second ; i++){
            //     res+=it.first;
            // }
            // Append maxChar to result maxCount times
            res.append(it.second, it.first);
        }
        return res;
    }
};

// brute ChatGPT : TLE
/*
TC : O(m * n)
SC : O(n)
*/


class Solution {
public:
    string frequencySort(string s) {
        string result = "";
        while (!s.empty()) {
            char maxChar = '\0';
            int maxCount = 0;

            // Find the character with the highest frequency
            for (char c : s) {
                int count = 0;
                for (char d : s) {
                    if (c == d) count++;
                }
                if (count > maxCount) {
                    maxCount = count;
                    maxChar = c;
                }
            }

            // Append maxChar to result maxCount times
            result.append(maxCount, maxChar);

            // Remove all occurrences of maxChar from the string
            s.erase(remove(s.begin(), s.end(), maxChar), s.end());
        }
        return result;
    }
};

// better solution : optimized my solution
// Optimize Sorting with a Bucket Sort Approach:
// Since the frequency of characters in a string is bounded by the string length n,
// we can use bucket sort instead of general-purpose sorting.

/*
	•	Frequency Count: O(n)
	•	Bucket Creation: O(m), where m is the number of unique characters.
	•	Result Building: O(n), as you iterate through all characters.

Time Complexity: O(n)
	•	This is more optimal than O(n + m \log m) since sorting is replaced by bucket traversal.

Space Complexity: O(n)
	•	Buckets use O(n) space, and the frequency map uses O(m).
*/
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freqMap;
        for (char c : s) {
            freqMap[c]++;
        }

        // Create buckets: each bucket at index i stores characters with frequency i
        vector<string> buckets(s.size() + 1);
        for (auto& [ch, freq] : freqMap) {
            buckets[freq].append(freq, ch); // Append the character `freq` times
        }

        // Build the result by traversing buckets in reverse order
        string result;
        for (int i = buckets.size() - 1; i > 0; --i) {
            if (!buckets[i].empty()) {
                result.append(buckets[i]);
            }
        }

        return result;
    }
};




// optimal solution


/*
1.	Frequency Count: O(n)
2.	Heap Operations:
•	Building the heap takes O(m*log m), where m is the number of unique characters.
•	Extracting elements from the heap takes O(m*log m).
3.	Result Construction: O(n)

Time Complexity: O(n + m*log m)

This matches your original solution in terms of time complexity but avoids sorting a full vector, 
making it more space-efficient.

Space Complexity: O(m)

The heap uses O(m) space, and the frequency map uses O(m). No additional large structures are created.
*/
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freqMap;
        for (char c : s) {
            freqMap[c]++;
        }

        // Use a max-heap (priority queue) to store characters by frequency
        priority_queue<pair<int, char>> maxHeap;
        /*
        This loop iterates over the frequency map (freqMap) and pushes each character along with its 
        frequency into the max-heap (maxHeap).

        Range-based For Loop:
            •	Iterates over all key-value pairs in the freqMap.
            •	auto& [ch, freq] destructures each pair into:
                •	ch: The character (key of the map).
                •	freq: The frequency (value of the map).

        maxHeap.push({freq, ch}):
            •	Creates a pair {freq, ch} and inserts it into the max-heap.
            •	The heap is automatically sorted in descending order based on the first element of the pair (freq).
            •	This ensures that the character with the highest frequency is always at the top of the heap.
        */
        for (auto& [ch, freq] : freqMap) {
            maxHeap.push({freq, ch});
        }

        // Build the result string by extracting from the heap
        string result;
        while (!maxHeap.empty()) {
            auto [freq, ch] = maxHeap.top();
            maxHeap.pop();
            result.append(freq, ch); // Append `freq` instances of `ch`
        }

        return result;
    }
};