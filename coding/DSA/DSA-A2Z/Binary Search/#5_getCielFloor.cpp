#include <bits/stdc++.h>
using namespace std;


int findFloor(int arr[], int n, int x) {
	int low = 0, high = n - 1;
	int ans = -1;

	while (low <= high) {
		int mid = (low + high) / 2;
		// maybe an answer
		if (arr[mid] <= x) {
			ans = arr[mid];
			//look for smaller index on the left
			low = mid + 1;
		}
		else {
			high = mid - 1; // look on the right
		}
	}
	return ans;
}

int findCeil(int arr[], int n, int x) {
	int low = 0, high = n - 1;
	int ans = -1;

	while (low <= high) {
		int mid = (low + high) / 2;
		// maybe an answer
		if (arr[mid] >= x) {
			ans = arr[mid];
			//look for smaller index on the left
			high = mid - 1;
		}
		else {
			low = mid + 1; // look on the right
		}
	}
	return ans;
}

pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
	int f = findFloor(arr, n, x);
	int c = findCeil(arr, n, x);
	return make_pair(f, c);
}

int main() {
	int arr[] = {3, 4, 4, 7, 8, 10};
	int n = 6, x = 5;
	// vector<int> result(2,-1);
	// for(auto it : result){
	// 	cout<<it<<", ";
	// }
	// cout<<endl;
	pair<int, int> ans = getFloorAndCeil(arr, n, x);
	cout << "The floor and ceil are: " << ans.first
	     << " " << ans.second << endl;
	return 0;
}

// trying to add a comment for literally no reason





// GFG for unsorted Array
class Solution {
public:
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        // code here
        vector<int> vec;
        int floor = INT_MIN , ceil = INT_MAX;
        for(int i = 0 ; i<arr.size() ; i++){
            if(arr[i]==x){
                vec.push_back(x);
                vec.push_back(x);
                return vec;
            }
            else if(arr[i]<x){floor=max(floor,arr[i]);}
            else{//arr[i]<x
                ceil=min(ceil,arr[i]);
            }
        }
        if(floor == INT_MIN ){floor = -1;}
        if(ceil == INT_MAX){ceil=-1;}
        vec.push_back(floor);
        vec.push_back(ceil);
        return vec;
    }
};

