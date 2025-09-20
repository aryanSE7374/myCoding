#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = friendships.size(); // no. of users
        // unordered_map<int , int> isVisited;
        // unordered_map<int , vector<int>> friends;
        // for(int i=0 ; i<m ; i++){
        //     // isVisited[i]++;
        //     vector<int> temp;
        //     for(int friendship : friendships[i]){
        //         temp.push_back(friendship);
        //         // if(isVisited.find(friendship)==isVisited.end()){
        //         //     isVisited[friendship]++;
        //         // }
        //     }
        //     friends[i+1] = temp;
        // }

        int ans = 0;

        unordered_map<int , vector<int>> languagesMap;
        for(int i=0 ; i<m ; i++){
            vector<int> temp;
            for(int language : languages[i]){
                temp.push_back(language);
            }
            languagesMap[i+1] = temp;
        }

        for(int i=0 ; i<m ; i++){
            int u1 = friendships[i][0];
            int u2 = friendships[i][1];
            // vector<int> language1 = languagesMap[u1];
            unordered_map<int , int> freq;
            for(int language : languagesMap[u1]){
                freq[language]++;
            }
            for(int language : languagesMap[u2]){
                freq[language]++;
            }
            int maxi = 0;
            for(auto it : freq){
                maxi = max(maxi , it.second);
            }
            ans = ans + 2-maxi;
        }

        return ans;
    }
       /*
        vector<int> freq(n,0); // 0-based indexing
        int maxi = 0;
        for(int i=0 ; i<m ; i++){
            for(int language : languages[i]){
                freq[language-1]++;
                maxi = max(maxi , freq[language-1]);
            }
        }
        return m-maxi;
       */
};


class Solution{
    public : 
        int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size(); // number of users
        
        // step1: convert each user's languages into a set for quick lookup
        vector<unordered_set<int>> knows(m+1);
        for (int i = 0; i < m; i++) {
            for (int lang : languages[i]) {
                knows[i+1].insert(lang);
            }
        }

        // step2: find problematic users
        unordered_set<int> problematic;
        for (auto& f : friendships) {
            int u = f[0], v = f[1];
            bool ok = false;
            for (int lang : knows[u]) {
                if (knows[v].count(lang)) { ok = true; break; }
            }
            if (!ok) {
                problematic.insert(u);
                problematic.insert(v);
            }
        }

        if (problematic.empty()) return 0;

        // step3: try each language
        int ans = INT_MAX;
        for (int lang = 1; lang <= n; lang++) {
            int cnt = 0;
            for (int user : problematic) {
                if (!knows[user].count(lang)) cnt++; // if not found
            }
            ans = min(ans, cnt);
        }

        return ans;
    }
};