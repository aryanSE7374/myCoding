#include <iostream>
#include <string>
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    --x; // 0-based index

    string s;
    cin >> s;

    int hamid_pos = x;
    int ans = 0;

    while (true) {

        ans++;

        // mani move to block easy side
        
        int l_Walls = 0, r_Walls = 0;

        for (int i = 0; i < hamid_pos; ++i) if (s[i] == '#') l_Walls++;

        for (int i = hamid_pos + 1; i < n; ++i) if (s[i] == '#') r_Walls++;

        int mani_Wall_P = -1;

        if (l_Walls <= r_Walls) {

            for (int i = hamid_pos - 1; i >= 0; --i) {

                if (s[i] == '.') {

                    s[i] = '#';

                    mani_Wall_P = i;

                    break;
                }
            }

            if (mani_Wall_P == -1) {

                for (int i = hamid_pos + 1; i < n; ++i) {
                    
                    if (s[i] == '.') {

                        s[i] = '#';

                        break;
                    }
                }
            }
        } else {
            for (int i = hamid_pos + 1; i < n; ++i) {

                if (s[i] == '.') {

                    s[i] = '#';

                    mani_Wall_P = i;

                    break;
                }
            }
            if (mani_Wall_P == -1) {
                for (int i = hamid_pos - 1; i >= 0; --i) {

                    if (s[i] == '.') {

                        s[i] = '#';

                        break;
                    }
                }
            }
        }

        // hamid move to break easy side

        l_Walls = 0, r_Walls = 0;

        for (int i = 0; i < hamid_pos; ++i) if (s[i] == '#') l_Walls++;

        for (int i = hamid_pos + 1; i < n; ++i) if (s[i] == '#') r_Walls++;


        if (l_Walls == 0 || r_Walls == 0) break;

        if (l_Walls <= r_Walls) {

            for (int i = hamid_pos - 1; i >= 0; --i) {

                if (s[i] == '#') {

                    s[i] = '.';

                    hamid_pos = i;

                    break;
                }
            }
        } else {

            for (int i = hamid_pos + 1; i < n; ++i) {

                if (s[i] == '#') {

                    s[i] = '.';

                    hamid_pos = i;

                    break;
                }
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}