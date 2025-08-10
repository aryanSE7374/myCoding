#include <iostream>
#include <vector>
using namespace std;

// Implement your logic here
string isInEquilibrium(const vector<vector<int>>& forces) {
    // TODO: Implement logic to check if body is in equilibrium
    int x=0 , y=0 , z=0;
    for(vector<int> force : forces){
        x+=force[0];
        y+=force[1];
        z+=force[2];
    }
    if(x || y || z){
        return "NO";
    }
    return "YES";
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> forces(n, vector<int>(3));
    for (int i = 0; i < n; ++i) {
        cin >> forces[i][0] >> forces[i][1] >> forces[i][2];
    }

    cout << isInEquilibrium(forces) << endl;

    return 0;
}
