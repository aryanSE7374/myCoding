//Given two strings, we need to check if these strings are Anagram of each other or not.
// Given two strings, check whether two strings are an anagram of each other. Two strings 
// are said to be an anagram of each other if they are just permutations of each other.
//  That is, the set of characters in both the strings must be the same, only the order
//  of characters can be different.
// Input: string1 = "abcd"
//        string2 = "bcad"
// Output: Yes

// Input: string1 = "listen"
//        string2 = "silent"
// Output: Yes


#include <bits/stdc++.h> 
using namespace std; 
  
//Naive solution
// TC : O(nlog(n))
bool areAnagram(string &s1, string &s2) 
{ 
    int n1 = s1.length(); 
    int n2 = s2.length(); 
    if (n1 != n2) 
        return false; 
  
    sort(s1.begin(), s1.end()); 
    sort(s2.begin(), s2.end()); 
  
    return (s1==s2); 
} 


//efficient solution
// TC  : O(n)
// AS : O(CHAR) -- constant
const int CHAR=256;
bool areAnagramEff(string &s1, string &s2) 
{ 
    int n1 = s1.length(); 
    int n2 = s2.length(); 
    if (n1 != n2) 
        return false; 
    
    int count[CHAR]={0};
    for(int i=0;i<s1.length();i++){
        count[s1[i]]++;
        count[s2[i]]--;
    }
    
    for(int i=0;i<CHAR;i++){
        if(count[i]!=0)return false;
    }
    return true;
} 
 
int main() 
{ 
    
    string str1 = "abaac"; 
    string str2 = "aacba"; 
    cout<<"by Naive Method: ";
    if (areAnagram(str1, str2)) 
        cout << "The two strings are anagram of each other"; 
    else
        cout << "The two strings are not anagram of each other";
    cout<<"\n";
    cout<<"by Efficient  Method: ";
    if (areAnagramEff(str1, str2)) 
        cout << "The two strings are anagram of each other"; 
    else
        cout << "The two strings are not anagram of each other"; 
    cout<<"\n";
    return 0; 
} 