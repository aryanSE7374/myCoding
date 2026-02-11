#include<bits/stdc++.h>
using namespace std;



int main(){
    int t;
    cin>>t;
    
    while(t--){
    
        int num;
        cin>>num;
        vector<vector<int>> v(num);


        for(int i=0; i<num; i++){
            int size;
            cin>>size;
            
            for(int j=0; j<size; j++){
                int x;
                cin>>x;
                v[i].push_back(x);
            }
            
            sort(v[i].begin(),v[i].end());
            
        }

        unordered_map<int,vector<int>> mp;
        unordered_map<int,vector<int>> mp2;
        int sum=0;

        for(int i=0; i<v.size(); i++){
            bool flag=true;
            int ans=0;
            int init;
            int final;
            
            for(int j=0; j<v[i].size(); j++){
            
                if(v[i][j]>ans){
                    flag=false;
                    init=ans;
                    ans=init+1;
                    final=-1;
                    
                    for(int k=j; k<v[i].size(); k++){
                        if(v[i][k]>ans){
                            final=ans;
                            break;
                        }
                        
                        if(ans==v[i][k]){
                            ans++;
                        }
                    }
                    
                    if(final==-1){
                        final=v[i][v[i].size()-1]+1;
                    }
                    
                    break;
                }
                
                
                if(ans==v[i][j]){
                    ans++;
                }
            
            }
            
            if(flag){
                init=v[i][v[i].size()-1]+1;
                final=init+1;
            }
            
            mp[i].push_back(init);
            mp[i].push_back(final);
            
            mp2[init].push_back(final);
            
            sum+=init;
        }

        unsigned long long int result=0;

        for(int i=0; i<v.size(); i++){
            for(int j=0; j<v[i].size(); j++){
            
                unsigned long long int sumx=sum;
                unsigned long long int select=v[i][j]; 
                
                if(v[i].size()>1 && ((mp[i][0]>select && j==v[i].size()-1 && select!=v[i][j-1] ) || (mp[i][0]>select && j==0 && select!=v[i][j+1]) || (mp[i][0]>select && j<(v[i].size()-1) && j>0 && v[i][j+1]!=select && v[i][j-1]!=select)) ){
                    sumx=sum-mp[i][0]+select;
                }
                
                if(v[i].size()==1 && v[i][j]==0){
                    sumx=sum-mp[i][0];
                }
                
                unsigned long long int remain=num-1-mp2[select].size();
                
                unsigned long long int plus=0;

                for(int k=0; k<mp2[select].size(); k++){
                    plus+=mp2[select][k];
                }
                
                
                
                unsigned long long int arr_size=mp2[select].size();
                // cout<<"arr.size(): "<<arr_size<<" "<<"remain: "<<remain<<" "<<"sumX: "<<sumx<<endl;
                
                result+=(unsigned long long int)(sumx*remain) + (unsigned long long int)((unsigned long long int)(sumx-select)*(unsigned long long int)arr_size + (unsigned long long int)plus);
                // cout<<sumx<<endl;
            }
        }
        
        cout<<result<<endl;
    
    }
    
    return 0;
}