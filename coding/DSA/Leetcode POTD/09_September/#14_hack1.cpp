#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mistake1(unordered_map<string , int>& capList , string query ){
        transform(query.begin(),query.end(),query.begin(),::toupper);
        if(capList.find(query)!=capList.end()){
            return capList[query];
        }
        return -1;
    }
    int mistake2(unordered_map<string , int>& capVowelList , string query ){
        transform(query.begin(),query.end(),query.begin(),::toupper);
        for(int i=0 ; i<query.size() ; i++){
            if(query[i]=='A' || query[i]=='E' || query[i]=='I' ||  query[i]=='O' ||  query[i]=='U' ){
                query[i] = '#';
            }
        }
        if(capVowelList.find(query)!=capVowelList.end()){
            return capVowelList[query];
        }
        return -1;

    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {


        int n = wordlist.size();
        int q = queries.size();
        // vector<string> capList = wordlist;
        unordered_map<string , int> wordlistMap;
        unordered_map<string , int> capList;
        unordered_map<string , int> capVowelList;

        for(int i=0 ; i<n ; i++){
            string temp = wordlist[i];
            wordlistMap[temp] = i;
            transform(temp.begin(),temp.end(),temp.begin(),::toupper);
            // capList[temp] = i;

            if (capList.find(temp) == capList.end()) capList[temp] = i;

            for(int i=0 ; i<temp.size() ; i++){
                if(temp[i]=='A' || temp[i]=='E' || temp[i]=='I' ||  temp[i]=='O' ||  temp[i]=='U' || 
                temp[i]=='a' || temp[i]=='e' || temp[i]=='i' ||  temp[i]=='o' ||  temp[i]=='u' ){
                    temp[i] = '#';
                }
            }

            if (capVowelList.find(temp) == capVowelList.end()) capVowelList[temp] = i;

            // capVowelList[temp] = i;

        }

        vector<string> res(q,"");

        for(int i=0 ; i<q ; i++){

            // 1. exact match
            if(wordlistMap.find(queries[i])!=wordlistMap.end()){
                res[i] = queries[i];
                continue;
            }

            // 2. capitalize error check

            int m1 =  mistake1(capList , queries[i]);
            if( m1 != -1 ){
                res[i] = wordlist[m1];
                continue;
            }

            // 3. vowel error check

            int m2 =  mistake2(capVowelList , queries[i]);
            if( m2 != -1 ){
                res[i] = wordlist[m2];
            }
        }

        return res;

    }
};