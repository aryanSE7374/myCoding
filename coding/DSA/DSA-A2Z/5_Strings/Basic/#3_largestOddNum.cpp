#include<bits/stdc++.h>
using namespace std;


// my Brute sol :

// TC: O(n) - The loop iterates through the string once from right to left.
// SC: O(n) - Creating the resultant string, which in the worst case can be the entire input string.

class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size(); // Length of the input string
        int idx = n; // Initialize idx to an invalid index
        string str = ""; // To store the resultant substring

        // Find the last odd digit in the string
        for (int i = n - 1; i >= 0; i--) {
            if ((int(num[i]) - 48) % 2 == 1) { // Check if the digit is odd
                idx = i;
                break; // Exit the loop once we find the last odd digit
            }
        }

        // If no odd digit is found, return an empty string
        if (idx == n) {
            return str;
        }

        // Append characters from the start to idx
        for (int i = 0; i <= idx; i++) {
            str += num[i];
        }

        return str; // Return the resultant string
    }
};



// my optimal sol : 

// TC: O(n) - The loop iterates through the string once from right to left.
// SC: O(1) - Using the `substr` function directly avoids additional space for concatenation.
 
class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        int idx = n;
        string str = "";
        for(int i = n-1 ; i>=0 ; i-- ){
            if((int(num[i]))%2==1){
                idx = i;
                break;
            }
        }
        // If no odd digit is found, return an empty string
        if(idx==n){return str;}
        // If the last odd digit is the last digit of the string, return the input string
        else if(idx==n-1){return num;}
        // for(int i = 0 ; i<=idx ; i++){
        //     str+=num[i];
        // }
        // Use substr to extract the substring from 0 to idx (inclusive)
        str = num.substr(0,idx+1); // substr(start_idx , length);
        return str;
    }
};


// my optimal try 2 => better solution
// TC : O(n)
// SC : O(n) , AS : O(1)

class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        for(int i = n-1 ; i>=0 ; i-- ){
            if(num[i]%2==1){
                return num.substr(0,i+1);
            }
        }
        return "";
    }
};

// most optimal
// TC : O(n)
// SC : O(1) , AS : O(1)

class Solution {
public:
    string largestOddNumber(string num) {
        for (int i = num.size() - 1; i >= 0; --i) {
            if ((num[i] - '0') % 2 == 1) {
                num.resize(i + 1); // Resize the string to the valid substring
                return num;
            }
        }
        return ""; // No odd number found
    }
};

// driver code

int main(){
    char c = '0';
    cout<<(c%2)<<endl;
    return 0;
}

