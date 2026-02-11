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



// ----- //


/*

approach : 

let s be divided into two categories : s[0] = a and s[0] = b

a1 = frst occ of 'a' in s
am = last occ of 'a' in s

b1 = frst occ of 'b' in s
bk = last occ of 'b' in s

s-case-1 : [ a1 ...... am ] 
                  [ b1 ....... bk]


s-case-2 : [ b1 ....... bk]
                  [ a1 ...... am ] 


c1 = total a's , c2 = total b's

if ( s[0] = a ) : 
    case1-1 : 
        remove all bad b's : cnt of b's before last a (am) = c3

    case1-2 : 
        remove all bad a's : cnt of a's after first b (b1) = c4

if ( s[0] = b ) :
    case2-1 : 
        remove all bad a's : c1 = cnt of total a's (case when all b's is balanced)

    case2-2 : 
        remove all bad b's : cnt of b's before last a (am) = c5


*/

class Solution {
public:
    int minimumDeletions(string s) {

        int n = s.size();

        int a1 = -1 , am = -1;
        int b1 = -1 , bk = -1;

        int c1 = 0 , c2 = 0; // total a , b

        for ( int i = 0 ; i < n ; i++ ) {

            if ( s[i] == 'a' ) {
                c1++;
                if ( a1 == -1 ) a1 = i;
                am = i;
            }
            else {
                c2++;
                if ( b1 == -1 ) b1 = i;
                bk = i;
            }
        }

        // Edge case: already balanced
        if ( c1 == 0 || c2 == 0 ) return 0;

        int ans = INT_MAX;

        if ( s[0] == 'a' ) {

            // case1-1: remove all bad b's before last a
            int c3 = 0;
            for ( int i = 0 ; i < am ; i++ ) {
                if ( s[i] == 'b' ) c3++;
            }

            // case1-2: remove all bad a's after first b
            int c4 = 0;
            for ( int i = b1 + 1 ; i < n ; i++ ) {
                if ( s[i] == 'a' ) c4++;
            }

            ans = min(c3, c4);
        }
        else { // s[0] == 'b'

            // case2-1: remove all a
            int case1 = c1;

            // case2-2: remove b before last a
            int c5 = 0;
            for ( int i = 0 ; i < am ; i++ ) {
                if ( s[i] == 'b' ) c5++;
            }

            ans = min(case1, c5);
        }

        return ans;
        
    }
};

// ---- //

int main(){
    
    return 0;
}