/*
code by - Aryan Shrivastav
*/

/*
observations : 
map first and second appearance of each number
intially the answer is 1, for min possible subarray i.e. selecting {0}
then check for zero : 
    subarray btw a+1 .... b-1 should also be pallindrome

then if checks passed : 
    expand from zeroes indices
        a-1 and b+1 
        untill any of the bounds reached or the pallindrome fails
        keep track all the numbers selected and then find the mex among them

*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
#define pii pair<int,int>
#define pll pair<long long,long long>
#define f(i,a,n) for(int i=a ; i<n ; i++)

int get_mex(vi &nums) {
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    int m = nums.size();
    for (int i = 0; i<m; i++) {
        if (nums[i] != i) return i;
    }
    return nums.size();
}

vi expand(int l, int r, vi &a, int N) {
    vi nums;
    while (l >= 0 && r < N && a[l] == a[r]) {
        nums.push_back(a[l]);
        l--;
        r++;
    }
    return nums;
}

bool is_palindrome(int l, int r, vi &a) {
    while (l <= r) {
        if (a[l] != a[r]) return false;
        l++; r--;
    }
    return true;
}

void SOLVE() {

    int n;
    cin >> n;

    int N = 2 * n;
    vi a(N);

    vector<pair<int,int>> index(n, {-1,-1});

    for (int i=0; i<N; i++) {
        cin >> a[i];

        if (index[a[i]].first == -1) {
            index[a[i]].first = i;
        }
        else {
            index[a[i]].second = i;
        }

    }

    int x = index[0].first;
    int y = index[0].second;

    // CASE 1

    int mini = 1;
    vi nums = {0};

    if (is_palindrome(x+1, y-1, a)) {

        int i = x+1, j = y-1;

        while (i <= j) {
            nums.push_back(a[i]);
            i++; 
            j--;
        }

        vi outer = expand(x-1, y+1, a, N);
        nums.insert(nums.end(), outer.begin(), outer.end());
        mini = get_mex(nums);

    }

    // CASE 2a

    vi nums2 = {0};

    vi left = expand(x-1, x+1, a, N);
    nums2.insert(nums2.end(), left.begin(), left.end());

    int mini2 = get_mex(nums2);

    // CASE 2b

    vi nums3 = {0};

    vi right = expand(y-1, y+1, a, N);
    nums3.insert(nums3.end(), right.begin(), right.end());

    int mini3 = get_mex(nums3);

    // ans : max of all 3 cases

    cout << max({mini, mini2, mini3});

    cout << '\n';

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        SOLVE();
    }
    return 0;
}