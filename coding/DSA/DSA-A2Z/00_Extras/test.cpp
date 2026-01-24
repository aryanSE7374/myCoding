#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {

        int n = nums.size() ;
        vector<int> res(n,-1) ;

        for ( int i=0 ; i<n ; i++ ) {

            int32_t numsi = nums[i] , curr = 1 , mini = numsi ;
            cout << "i = " << i << endl ;
            for ( int d=0 ; d<32 ; d++ ) {
                cout << "curr - " << curr << " , " ;
                int32_t ans = numsi & ( !curr ) ;
                cout << "ans - "  << ans << "\n" ;
                if ( ans | (ans+1) == numsi ) mini = min ( mini , ans );
                curr << 1 ; 
            }
            cout << endl ;

            if ( mini < numsi ) res[i] = (int)mini ;

        }

        return res ;

    }
};

// ---------------------------------------------------------------- //


class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {

        int m = mat.size(), n = mat[0].size();

        vector<vector<int>> ps(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                ps[i][j] = mat[i-1][j-1] + ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1];
            }
        }

        int low = 0, high = min(m, n), ans = 0;

        while (low <= high) {
            int k = (low + high) / 2;
            bool possible = false;

            for (int r = 0; r + k <= m && !possible; r++) {
                for (int c = 0; c + k <= n; c++) {

                    int sum = ps[r + k][c + k] - ps[r][c + k] - ps[r + k][c] + ps[r][c];

                    if (sum <= threshold) {
                        possible = true;
                        break;
                    }
                }
            }

            if (possible) {
                ans = k;
                low = k + 1;
            } else {
                high = k - 1;
            }
        }

        return ans;
    }
};

int main(){
    
    return 0;
}