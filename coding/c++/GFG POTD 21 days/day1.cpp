#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
  public:
    int isCircle(vector<string> &arr) {
        int n = arr.size();
        //{1: "asd",2: "ryr",3: "fgr",4: "dgf",5: "ert",6: "fde",7: "yta",8: "dse",9: "qwd",10: "fds"}
        // 2 hasmaps if len(arr[i]>1) : frst letter , last letter 
        //first //{1-a , 2-r , 3-f , 4-d , 5-e , 6-f , 7-y , 8-d , 9-q , 10-f}
        //last //{1-d , 2-r , 3-r , 4-f , 5-t , 6-e , 7-a , 8-e , 9-d , 10-s}
    }
};


//{1: "asd",2: "ryr",3: "fgr",4: "dgf",5: "ert",6: "fde",7: "yta",8: "dse",9: "qwd",10: "fds"}
// 2 hasmaps if len(arr[i]>1) : frst letter , last letter 
//first //{1-`` , 2-r , 3-f , 4-d , 5-e , 6-f , 7-y , 8-d , 9-q , 10-f}
//last //{1-`` , 2-r , 3-r , 4-f , 5-t , 6-e , 7-a , 8-e , 9-d , 10-s}
//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> A;
        string s;

        for (int i = 0; i < N; i++) {
            cin >> s;
            A.push_back(s);
        }

        Solution ob;
        cout << ob.isCircle(A) << endl;
    }
    return 0;
}
// } Driver Code Ends