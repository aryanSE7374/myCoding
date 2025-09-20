#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findClosest(int x, int y, int z) {
        int difference_xz = abs(z-x);
        int difference_yz = abs(z-y);
        if(difference_xz < difference_yz) return 1;
        if(difference_xz > difference_yz) return 2;
        else return 0;
    }
};