#include<bits/stdc++.h>
using namespace std;

void fill_q(vector<int> &p , vector<int> &q , int n ){

    vector<int> mod0_indices;
    vector<int> mod1_indices;
    vector<int> mod2_indices;

    for(int i=0 ; i<n ; i++){
        if(p[i]%3==0){
            mod0_indices.push_back(i);
        }
        else if(p[i]%3==1){
            mod1_indices.push_back(i);
        }
        else{
            mod2_indices.push_back(i);
        }
    }

    vector<int> mod0_available;
    vector<int> mod1_available;
    vector<int> mod2_available;

    for(int k=1 ; k<=n ; k++){
        if(k%3==0){
            mod0_available.push_back(k);
        }
        else if(k%3==2){
            mod1_available.push_back(k);
        }
        else{
            mod2_available.push_back(k);
        }
    } 

    int m0 = mod0_indices.size();
    int m1 = mod1_indices.size();
    int m2 = mod2_indices.size();

    for(int i = 0 ; i<m0 ; i++){
        int index = mod0_indices[i];
        int val = mod0_available[i];
        q[index] = val;
    }
    for(int i = 0 ; i<m1 ; i++){
        int index = mod1_indices[i];
        int val = mod1_available[i];
        q[index] = val;
    }
    for(int i = 0 ; i<m2 ; i++){
        int index = mod2_indices[i];
        int val = mod2_available[i];
        q[index] = val;
    }

}

int main(){
    int t;
    cin>>t;
    while (t-->0)
    {
        int n;
        cin>>n;
        vector<int> p(n);
        for(int i=0 ; i<n ; i++){
            cin>>p[i];
        }

        vector<int> q(n);
        fill_q(p , q , n);

        for(int num : q){
            cout<<num<<" ";
        }

        cout<<endl;
    }   
}