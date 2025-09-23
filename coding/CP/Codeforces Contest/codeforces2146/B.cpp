#include <bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t-->0){
        int n, m;
        cin>>n; 
        cin>>m;

        vector<vector<int>> sets(n);
        vector<vector<int>> parent(m+1);

        for(int i = 0; i < n; i++){
            int li;
            cin>>li;
            sets[i].resize(li);
            for(int j = 0; j < li; j++){
                cin>>sets[i][j];
                parent[sets[i][j]].push_back(i);
            }
        }

        bool flag = true;
        set<int> mandatory; 

        for (int x = 1; x <= m; x++){
            if(parent[x].empty()){
                flag = false;
                break;
            }
            if(parent[x].size() == 1){
                mandatory.insert(parent[x][0]);
            }
        }

        if(!flag){
            cout<<"NO\n";
        } 
        else if(mandatory.size() >= 2){
            cout<<"NO\n";
        } 
        else {
            cout<<"YES\n";
        }

    }

    return 0;

}