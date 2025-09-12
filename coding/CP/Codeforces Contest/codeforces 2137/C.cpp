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

    long long k = find_second_divisor(b);

    if(k==1){
        return ((a+b)%2==0) ? a+b : -1;
    }

    while(b>0){
        a*=k;
        b/=k;
        if(b!=0){
            if((a+b)%2==0){
                sum = max(sum , a+b);
            }
        }
    }
    return sum;
    
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