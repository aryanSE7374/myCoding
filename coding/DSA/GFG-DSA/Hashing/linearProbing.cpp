// linear probing in hashing
/*Linear probing is a collision-handling technique in hashing. Linear probing says that whenever a collision occurs, 
search for the immediate next position.

Given an array of integers and a hash table size. Fill the array elements into a hash table using Linear Probing to
 handle collisions. Duplicate elements must be mapped to the same position in the hash table while colliding elements 
 must be mapped to the [(value+1)%hashSize] position.

Note :-  If there's no more space to insert a new element, just drop that element. 

Example 1:

Input:
hashSize = 10
sizeOfArray = 4 
Array[] = {4,14,24,44}
Output:
-1 -1 -1 -1 4 14 24 44 -1 -1
Explanation: 4%10=4. So put 4 in 
hashtable[4].Now, 14%10=4, but 
hashtable[4] is alreadyfilled so put 
14 in the next slot and so on.

Example 2:

Input:
hashSize = 10
sizeOfArray = 4 
Array[] = {9,99,999,9999}
Output:
99 999 9999 -1 -1 -1 -1 -1 -1 9
Explanation: 9%10=9. So put 9 in 
hashtable[9]. Now, 99%10=9, but 
hashtable[9] is already filled so 
put 99 in the (99+1)%10 =0 slot so
99 goes into hashtable[0] and so on.
*/


#include<bits/stdc++.h>
// #include<iostream>
using namespace std;
class Solution {
  public:
    // Function to fill the array elements into a hash table
    // using Linear Probing to handle collisions.
    vector<int> linearProbing(int hashSize, int arr[], int sizeOfArray) {
        vector<int> v(hashSize , -1);//initialized a vector of size hashSize and value -1 to each element
        for (int i = 0; i < sizeOfArray; i++) //iterating every element in vector
        {
            //check whether seen before or not, if yes then ignore/continue
            auto it = find(v.begin() , v.end() , arr[i]);
            if(it!=v.end())
            {
                continue;
            }
            //intialize val
            int val = arr[i]%hashSize;
            //check if the slot in hashtable is empty or not
            if(v[val]== -1 ){
                //if empty then put the value in hashtable and continue
                v[val] = arr[i];
                continue;
            }
            //increment val to check for next elements
            val++;
            
            //using modular arithmetics, check for either found an empty slot or completed a loop of the table
            while ((v[(val)%hashSize]!=-1)&&((val%hashSize)!=arr[i]%hashSize))
            {
                val++;
            }
            //check if the loop breaked brcause of empty slot or loop completion
            if ((val%hashSize)!=arr[i]%hashSize)
            {
                //if loop not completed ,then the put the value itno the hash table
                v[val%hashSize] = arr[i];
            }   
        }
        return v;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int hashSize;
        cin >> hashSize;

        int sizeOfArray;
        cin >> sizeOfArray;
        int arr[sizeOfArray];

        for (int i = 0; i < sizeOfArray; i++)
            cin >> arr[i];

        vector<int> hash;
        Solution obj;

        hash = obj.linearProbing(hashSize, arr, sizeOfArray);

        for (int i = 0; i < hashSize; i++)
            cout << hash[i] << " ";

        cout << endl;
    }
    return 0;
}

// } Driver Code Ends