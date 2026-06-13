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


void SOLVE(){

    int n;
    cin >> n;

    int N = 2*n;
    vi a(N);

    vector<pair<int, int>> index(n, {-1,-1}); // {first appearance, second appearance}

    f(i,0,N) {
        cin >> a[i];
        if ( index[a[i]].first == -1 ) index[a[i]].first = i;
        else index[a[i]].second = i;
    }

    // case 1 : expand around two points 

    vector<int> nums;
    nums.push_back(0);

    int x = index[0].first;
    int y = index[0].second;

    int i = x+1, j = y-1;

    bool flag1 = true;

    while ( i <= j ) {
        if ( a[i] != a[j] ) {
            // cout << 1 << endl;
            flag1 = false;
            break;
        }
        nums.push_back(a[i]);
        i++;
        j--;
    }

    int mini = INT_MAX;
    int m;

    if ( flag1 ) {
        i = x-1;
        j = y+1;

        while ( i>=0 && j<N && (a[i] == a[j]) ) {
            nums.push_back(a[i]);
            i--;
            j++;
        }

        // find mex in nums

        sort ( nums.begin(), nums.end() );

        // cout << "nums : " ;

        // for ( int& num : nums ) {
        //     cout << num << " ";
        // }

        // cout << endl;

        m = nums.size();
        for ( int i=0; i<m-1; i++ ) {
            if ( nums[i] == nums[i+1] ) continue;
            if ( nums[i]+1 != nums[i+1] ) {
                mini = nums[i] + 1;
                break;
            }
        }

        if ( mini == INT_MAX ) {
            mini = nums[m-1]+1;
        }
    }
    else {
        mini = 1;
    }

    

    // case 2 : expand around single point - we have 2 zeroes
    // case 2a - frst ze, case 2b - sec ze

    // 2a
    nums.clear();
    nums.push_back(0);

    i = index[0].first - 1;
    j = index[0].first + 1;

    while ( i>=0 && j<N && (a[i] == a[j]) ) {
        nums.push_back(a[i]);
        i--;
        j++;
    }

    sort ( nums.begin(), nums.end() );

    int mini2 = INT_MAX;
    m = nums.size();
    for ( int i=0; i<m-1; i++ ) {
        if ( nums[i] == nums[i+1] ) continue;
        if ( nums[i]+1 != nums[i+1] ) {
            mini2 = nums[i] + 1;
            break;
        }
    }

    if ( mini2 == INT_MAX ) {
        mini2 = nums[m-1]+1;
    }

    // 2b
    nums.clear();
    nums.push_back(0);

    i = index[0].second - 1;
    j = index[0].second + 1;

    while ( i>=0 && j<N && (a[i] == a[j]) ) {
        nums.push_back(a[i]);
        i--;
        j++;
    }

    sort ( nums.begin(), nums.end() );

    int mini3 = INT_MAX;
    m = nums.size();
    for ( int i=0; i<m-1; i++ ) {
        if ( nums[i] == nums[i+1] ) continue;
        if ( nums[i]+1 != nums[i+1] ) {
            mini3 = nums[i] + 1;
            break;
        }
    }

    if ( mini3 == INT_MAX ) {
        mini3 = nums[m-1]+1;
    }


    // max of all 3
    cout << max({mini, mini2, mini3});

    // f(i,0,N){
    //     if ( i > index[a[i]].first ) continue;
    //     cout << a[i] << " : " << index[a[i]].first << " , " << index[a[i]].second << endl;
    // }

    cout<<'\n';
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