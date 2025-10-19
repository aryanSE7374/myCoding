#include <bits/stdc++.h>
using namespace std;

// Helper function to calculate max perimeter from a frequency map and total sum
long long calculate_perimeter(map<long long,int> freq, long long total_sum) {
    vector<long long> odd;
    for(auto &it: freq) {
        if(it.second % 2 != 0){
            odd.push_back(it.first);
        } 

    }
    
    sort(odd.begin(), odd.end());
    
    // // Remove smallest odd-count sticks until at most 2 remain

    // while(odd.size() > 2) {
    //     total_sum -= odd[0];
    //     freq[odd[0]]--;
    //     if(freq[odd[0]] == 0) freq.erase(odd[0]);
    //     odd.erase(odd.begin());
    // }

    int remove_count = odd.size() - 2;  // number of smallest odd sticks to remove
    for(int i = 0; i < remove_count; i++){
        total_sum -= odd[i];
        freq[odd[i]]--;
        if(freq[odd[i]] == 0) freq.erase(odd[i]);
    }
    
    if(freq.empty()) return 0;
    
    long long mx = freq.rbegin()->first;
    if(2 * mx < total_sum) return total_sum;


    // If degenerate, try removing the largest stick (simulate Scenario 2)
    long long total_after_removal = total_sum - mx;
    
    // Check if largest remaining stick now works
    if(freq.size() == 1) return 0; // only one stick left → cannot form polygon
    
    freq[mx]--;
    if(freq[mx] == 0) freq.erase(mx);
    
    long long new_mx = freq.rbegin()->first;
    if(2 * new_mx < total_after_removal) return total_after_removal;
    
    // If still degenerate, polygon impossible
    return 0;


}

void SOLVE(vector<long long>& arr) {
    int n = arr.size();
    map<long long,int> freq;
    long long total_sum = 0;
    long long overall_max = 0;

    for(auto x: arr){
        freq[x]++;
        total_sum += x;
        overall_max = max(overall_max, x);
    }

    long long ans1 = calculate_perimeter(freq, total_sum);

    // Scenario 2: remove the largest stick if needed
    if(n > 0){
        freq[overall_max]--;
        if(freq[overall_max] == 0) freq.erase(overall_max);
    }
    long long ans2 = calculate_perimeter(freq, total_sum - overall_max);

    cout << max(ans1, ans2) << "\n";
}


int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
        }

        SOLVE(arr);
        cout<<endl;

    }

    return 0;
}