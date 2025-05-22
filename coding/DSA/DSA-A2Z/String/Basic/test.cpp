#include <iostream>
#include <string>
using namespace std;

int main() {
    string concatenated = "abcdeabcde";
    string goal = "cdeab";

    size_t pos = concatenated.find(goal);
    // cout << "Found at index: " << pos << endl;

    if (pos != string::npos) {
        cout << "Found at index: " << pos << endl;
    } else {
        cout << "Not found" << endl;
    }

    return 0;
}