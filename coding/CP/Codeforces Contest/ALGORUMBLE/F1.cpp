// GEMINI solution

/*
code by - Aryan Shrivastav
*/

/*
observations : 
// 1. Read N
// 2. Vector masks(N), lens(N)

// 3. Process Input
for (i from 0 to N-1):
    read string s
    lens[i] = s.length()
    mask = 0
    for char c in s:
        bit = c - 'a'
        mask = mask | (1 << bit) // Set the bit
    masks[i] = mask

// 4. Find Max Product
max_prod = 0
for (i from 0 to N-1):
    for (j from i+1 to N-1):
        if (masks[i] & masks[j]) == 0:
            // No common characters
            max_prod = max(max_prod, lens[i] * lens[j])

print max_prod
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define co_endl cout<<'\n'
#define f(i,a,n) for(int i=a ; i<n ; i++)

void SOLVE(){


    co_endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t-->0){

        SOLVE();

    }

    return 0;
}