#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-operations-to-make-array-elements-zero/

class Solution {
public:
    long long calc_total_cost(int x){
        // returns cost of reducing a num n to zero where unit cost performs one operation on x i.e. 
        // x = floor(x/4);

        if(x==0) return 0;

        long long n = x;
        long long total_cost = 0;
        long long k = 1;
        long long pow_4_k = 1;

        while (pow_4_k <= n / 4) {
            long long next_pow_4_k = pow_4_k * 4;
            total_cost += (next_pow_4_k - pow_4_k) * k;
            pow_4_k = next_pow_4_k;
            k++;
        }

        total_cost += (n - pow_4_k + 1) * k;
        return total_cost;

        // wrong computatuion technique for integers

        // long long k =  (long long)(log10(n)/log10(4)) + 1 ;

        // for(int i=1 ; i<k ; i++){
        //     total_cost += ( ((long long)pow(4,i)-(long long)pow(4,i-1)+1)*1LL*i );
        // }

        // total_cost += ( (1LL*n-(long long)pow(4,k-1)+1)*k );

        // return total_cost;

    }


    long long minOperations(vector<vector<int>>& queries) {
        // long long total_cost = 0;
        long long totalOps = 0;
        for(vector<int> query : queries){
            int l = query[0];
            int r = query[1];

            long long cost = calc_total_cost(r) - calc_total_cost(l-1);

            // total_cost += cost;
            long long Ops = (cost+1)/2; // ceil(cost/2)

            totalOps+=Ops;

        }

        return totalOps;

    }
};