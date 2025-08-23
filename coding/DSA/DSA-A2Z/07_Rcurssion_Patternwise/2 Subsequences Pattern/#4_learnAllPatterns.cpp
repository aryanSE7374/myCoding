#include <bits/stdc++.h>
using namespace std;

// type 1
// print All the subsequences with sum k

void printS(int ind, vector<int>& ds, int s, int sum, int arr[], int n) {
    if (ind == n) {
        if (s == sum) {
            for (auto it : ds) cout << it << " ";
            cout << endl;
        }
        return;
    }

    // Include the current element
    ds.push_back(arr[ind]);
    s += arr[ind];
    printS(ind + 1, ds, s, sum, arr, n);

    // Backtrack
    s -= arr[ind];
    ds.pop_back();

    // Exclude the current element
    printS(ind + 1, ds, s, sum, arr, n);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int arr[] = {1, 2, 1};
    int n = 3;
    int sum = 2;
    vector<int> ds;

    printS(0, ds, 0, sum, arr, n);

    return 0;
}


// type 2 

// print any one subsequence with sum k / check if there exists a subseq with sum k


bool printS2(int ind, vector<int>& ds, int s, int sum, int arr[], int n) {
    if (ind == n) {
        // condition satisfied
        if (s == sum) {
            for (auto it : ds) cout << it << " ";
            cout << endl;
            return true;
        }
        // condition not satisfied
        else return false;
    }

    // Pick the current element
    ds.push_back(arr[ind]);
    s += arr[ind];
    if (printS2(ind + 1, ds, s, sum, arr, n) == true)
        return true;

    // Backtrack
    s -= arr[ind];
    ds.pop_back();

    // Not pick the current element
    if (printS2(ind + 1, ds, s, sum, arr, n) == true)
        return true;

    return false;
}



// type 3 : count sub seq with sum = k

// Function to count all subsets with sum equal to target
int printS(int ind, int s, int sum, int arr[], int n) {

    // slight optimizations for only positive elements array case
    if(s>sum){return 0;}

    if (ind == n) {
        // base condition: if the current subset sum matches
        if (s == sum) return 1;
        else return 0;
    }

    // Pick the current element
    s += arr[ind];
    int l = printS(ind + 1, s, sum, arr, n);
    s -= arr[ind];  // backtrack

    // Not pick the current element
    int r = printS(ind + 1, s, sum, arr, n);

    return l + r;  // total ways by picking + not picking
}



