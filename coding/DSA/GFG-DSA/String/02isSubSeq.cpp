#include <bits/stdc++.h>
using namespace std;


//iterative solution
// TC : O(n+m)
// AS : O(1)
bool isSubSeqItr(string s1, string s2, int n, int m){
    int j = 0;
    
    for(int i = 0; i < n && j < m; i++){
        if(s1[i] == s2[j])
        j++;
    }
    
    return j == m;
}

//recursive
// TC : O(n+m)
// AS : O(n+m)
bool isSubSeq(string s1, string s2, int n, int m){
    if ( m == 0 )
        return true;
        
    if ( n == 0 )
        return false;
    
    if ( s1[n-1] == s2[m-1] )
        return isSubSeq(s1, s2, n-1, m-1);
    
    else
        return isSubSeq(s1, s2, n-1, m);
}


int main() {
	int n,m;//size of strings
	string s1, s2;
	cin>>n>>m;
	cin>>s1>>s2;
	
	cout<<"by iterative  method : "<<boolalpha<<isSubSeqItr(s1, s2, n, m)<<endl;
    cout<<"by iterative  method : "<<boolalpha<<isSubSeq(s1, s2, n, m)<<endl;
	
	return 0;
}