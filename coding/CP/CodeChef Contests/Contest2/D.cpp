/*
code by - Aryan Shrivastav
*/

/*
observations : 


Kadane's algo:

	prefA[i] = max subarr ending at i
	suffA[i] = max subarr start with i

	f(i,0,n) : 
	    curr = max(A[i] , curr + A[i])
	    prefA[i] = curr
	f(i=n-1;i>=0;i++) :
	    curr = max(A[i] , curr + A[i])
	    suffA[i] = curr


    lly B : prefB , suffB

ans:

	maxA[i] = prefA[i] + suffA[i] - A[i]
	maxB[i] = pref[i] + suffB[i] - B[i]

	ans = max  [i=0 ; n-1] { (maxA[i] + maxB[i]) }

*/  

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define co_endl cout<<'\n'
#define f(i,a,n) for(int i=a ; i<n ; i++)

void SOLVE(){

    int n;
    cin >> n;

    vll A(n);
    vll B(n);

    vll prefA(n);
    vll suffA(n);
    vll prefB(n);
    vll suffB(n);

    f(i,0,n){
        cin >> A[i];
        // if(i>0) prefA[i] = prefA[i-1] + A[i];
        // else prefA[0] = A[0];
    }

    f(i,0,n){
        cin >> B[i];
    }

    // f(i,0,n){
    //     suffB[n-i-1] = suffB[n-1] + B[n-i-1];
    // }

    ll curr = A[0];
    prefA[0] = A[0];

    f(i,1,n){
        curr = max(A[i] , curr + A[i]);
	    prefA[i] = curr;
    }

    curr = A[n-1];
    suffA[n-1] = A[n-1];

    for(int i=n-2 ; i>=0 ; i--){
	    curr = max(A[i] , curr + A[i]);
	    suffA[i] = curr;
    }

    curr = B[0];
    prefB[0] = B[0];

    f(i,1,n){
        curr = max(B[i] , curr + B[i]);
	    prefB[i] = curr;
    }

    curr = B[n-1];
    suffB[n-1] = B[n-1];

    for(int i=n-2 ; i>=0 ; i--){
	    curr = max(B[i] , curr + B[i]);
	    suffB[i] = curr;
    }


    ll ans = LLONG_MIN;

    f(i,0,n){

        ll maxA = prefA[i] + suffA[i] - A[i];
        ll maxB = prefB[i] + suffB[i] - B[i];

        ans = max(ans , maxA + maxB);

    }


    cout << ans;

    co_endl;
    
}

int main(){

    int t;
    cin>>t;
    while(t-->0){

        SOLVE();

    }

    return 0;
}