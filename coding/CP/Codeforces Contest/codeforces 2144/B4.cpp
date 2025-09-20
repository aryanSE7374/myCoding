#include<bits/stdc++.h>
using namespace std;

// This function is not used in the optimal approach, as we need to determine
// the *potential* to sort segments, not their current sorted state.
pair<int , int> checkSorted(vector<int> &p , int n , int start , int end){
    // returns unsorted range
    int l=start , r=end;
    while(l<=r){
        bool flag = false;
        if(l < n && p[l]==l+1){l++;flag=true;} // Added boundary check
        if(r >= 0 && p[r]==r+1){r--;flag=true;} // Added boundary check
        if(!flag){return {l,r};}
    }
    return {-1,-1};
}

// THIS IS THE CORRECTED SOLVE FUNCTION
void SOLVE(vector<int> &p , int n){
    // Your previous logic was a good attempt but failed because it only considers
    // the current state of sortedness and the span of zeros. The correct logic must
    // determine the longest prefix/suffix that *can* be made sorted.

    // STEP 1: Calculate prefix maximums. prefMax[k] will hold max(p[0]...p[k-1]).
    // This helps check if a prefix `0..k-1` could possibly contain numbers `{1..k}`.
    vector<int> prefMax(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefMax[i + 1] = max(prefMax[i], p[i]);
    }

    // STEP 2: Calculate suffix minimums. suffMin[k] will hold min(p[k]...p[n-1]).
    // This helps check if a suffix `k..n-1` could possibly contain numbers `{k+1..n}`.
    vector<int> suffMin(n + 1, n + 1);
    for (int i = n - 1; i >= 0; i--) {
        // Zeros are placeholders, so we treat them as a non-constraining large value.
        suffMin[i] = min(suffMin[i + 1], (p[i] == 0 ? n + 1 : p[i]));
    }

    // STEP 3: Find `l`, the length of the longest possible sorted prefix.
    // A prefix of length 'k' can be sorted if all its fixed numbers are less than or equal to 'k'.
    int l = 0;
    while (l < n && prefMax[l + 1] <= l + 1) {
        l++;
    }

    // STEP 4: Find `r`, the start index of the longest possible sorted suffix.
    // A suffix p[k..n-1] can be sorted if all its fixed numbers are greater than 'k'.
    int r = n;
    while (r > 0 && suffMin[r - 1] > r - 1) {
        r--;
    }

    // STEP 5: The max cost is the length of the central "unstable" region.
    // If the sortable prefix and suffix meet or overlap (l >= r), the cost is 0.
    if (l >= r) {
        cout << 0;
    } else {
        cout << r - l;
    }
}


int main(){
    // Added for faster I/O in competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t-->0){
        int n;
        cin>>n;
        vector<int> p(n,0);
        for(int i=0 ; i<n ; i++){
            cin>>p[i];
        }

        SOLVE(p , n);

        cout<<endl;
    }
    return 0;
}