#include<bits/stdc++.h>
using namespace std;


long long SOLVE(int n , int k , vector<int>& prods , vector<int>& disc){

    long long cost = 0;

    for(int prod : prods){
        cost += prod;
    }

    sort(prods.begin() , prods.end());
    sort(disc.begin() , disc.end());

    int p = n-1;
    int d = 0;

    while(d<k && p>=0){
        int x = disc[d];

        if(p-x+1<0){
            return cost;
        }
        cost -= prods[p-x+1];
        p = p-x;
        d++;
    }

    return cost;

}

int main(){
    int t;
    cin>>t;
    while(t-->0){
        int n;
        int k;

        cin>>n;
        cin>>k;

        vector<int> prods(n,0);
        vector<int> disc(k,0);

        for(int i=0 ; i<n ; i++){
            cin>>prods[i];
        }

        for(int i=0 ; i<k ; i++){
            cin>>disc[i];
        }

        cout<<SOLVE(n , k , prods , disc);

        cout<<endl;
    }

    return 0;
}