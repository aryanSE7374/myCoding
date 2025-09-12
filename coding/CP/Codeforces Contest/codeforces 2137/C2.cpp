#include<bits/stdc++.h>
using namespace std;


long long find_second_divisor(long long num){
    for(long long i=2 ; i*i <= num ; i++){
        if(num%i==0) return i;
    }
    return num;
}

long long solve(long long a , long long b){

    // find 2nd dvisor after 1 of b
    // check iteratively for that divisor

    long long sum = ((a+b)%2==0) ? a+b : -1;

    for (long long i = 1; i * i <= b; i++) {
        if (b%i == 0) {
            long long k1 = i;
            long long k2 = b/i;

            // k1
            long long sum1 = a*k1 + b/k1;
            if (sum1 % 2 == 0) sum = max(sum, sum1);

            // k2
            long long sum2 = a*k2 + b/k2;
            if (sum2 % 2 == 0) sum = max(sum, sum2);
        }
    }

    return sum;

    // long long k = find_second_divisor(b);

    // if(k==1){
    //     return ((a+b)%2==0) ? a+b : -1;
    // }

    // while(b>0){
    //     a*=k;
    //     b/=k;
    //     if(b!=0){
    //         if((a+b)%2==0){
    //             sum = max(sum , a+b);
    //         }
    //     }
    // }
    
    
}

int main(){
    long long t;
    cin>>t;
    while (t-->0)
    {
        long long a,b;

        cin>>a;
        cin>>b;

        cout<<solve(a , b);

        cout<<endl;

    }   

    return 0;

}