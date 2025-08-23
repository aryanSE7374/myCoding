#include<bits/stdc++.h>
using namespace std;
 
long long sumOfDigitsInSequence(long long k){
    long long sum = 0;
    long long num = 1;

    if(k<=9){
        // cout<<"k less than 9"<<endl;
        return k*(k+1)/2;
    }
    else{
        sum=45;
        k-=9;
        num=10;
        // cout<<"else sum:"<<sum<<"k:"<<k<<"num:"<<num<<endl;
    }

    while (k>0)
    {
        int digits = (int)log10(num) + 1;
        // cout<<"digits:"<<digits<<endl;
        long long dummyNum = num;
        // cout<<"dummyNum:"<<digits<<endl;
        if(digits>k){
            // cout<<"digits > k"<<endl;
            long long dummyNum = num / pow(10 , digits-k);
            // cout<<"dummyNum:"<<digits<<endl;
        }
        while(dummyNum>0){
            // cout<<"iteration...";
            sum += (dummyNum%10);
            dummyNum/=10;
        }
        // cout<<endl;
        k-=digits;
        num++;
        // cout<<"sum:"<<sum<<"k:"<<k<<"num:"<<num<<endl;
        
    }
    return sum;
}
 
int main() {
    int t;
    cin >> t;
    while (t-->0) {
        long long k; 
        cin >> k;
        cout<<sumOfDigitsInSequence(k)<< endl;
    }
    return 0;
}