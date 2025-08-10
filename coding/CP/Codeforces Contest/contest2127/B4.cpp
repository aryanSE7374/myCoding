#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// For the efficient solution, we need an order-statistic tree.
// This is a standard tool in competitive programming for this kind of problem.
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// A convenient alias for the order-statistic tree
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    int n;
    int x;
    cin >> n >> x;
    --x; // 0-based index

    string s;
    cin >> s;

    // These sets will efficiently track the positions of walls and empty cells
    ordered_set<int> walls;
    ordered_set<int> empty_cells;

    for (int i = 0; i < n; ++i) {
        if (s[i] == '#') {
            walls.insert(i);
        } else {
            // Mani can't build on Hamid's starting spot
            if (i != x) {
                empty_cells.insert(i);
            }
        }
    }

    int hamid_pos = x;
    int days = 0;

    // Simulate the game day by day
    while (true) {
        days++;

        // --- Mani's Move ---
        // He reinforces the side with fewer walls
        int walls_left = walls.order_of_key(hamid_pos);
        int walls_right = walls.size() - walls_left;

        if (!empty_cells.empty()) {
            if (walls_left <= walls_right) {
                // Try to place on the left side
                int empty_left_count = empty_cells.order_of_key(hamid_pos);
                if (empty_left_count > 0) {
                    // Find rightmost empty spot on the left and build a wall
                    int pos_to_fill = *empty_cells.find_by_order(empty_left_count - 1);
                    empty_cells.erase(pos_to_fill);
                    walls.insert(pos_to_fill);
                } else { // No empty spots on left, forced to place on right
                    int pos_to_fill = *empty_cells.find_by_order(empty_left_count);
                    empty_cells.erase(pos_to_fill);
                    walls.insert(pos_to_fill);
                }
            } else { // Try to place on the right side
                int empty_left_count = empty_cells.order_of_key(hamid_pos);
                if (empty_left_count < empty_cells.size()) {
                    // Find leftmost empty spot on the right and build a wall
                    int pos_to_fill = *empty_cells.find_by_order(empty_left_count);
                    empty_cells.erase(pos_to_fill);
                    walls.insert(pos_to_fill);
                } else { // No empty spots on right, forced to place on left
                    int pos_to_fill = *empty_cells.find_by_order(empty_left_count - 1);
                    empty_cells.erase(pos_to_fill);
                    walls.insert(pos_to_fill);
                }
            }
        }

        // --- Hamid's Move ---
        // He attacks the side with fewer walls
        walls_left = walls.order_of_key(hamid_pos);
        walls_right = walls.size() - walls_left;
        
        // Check for escape condition
        if (walls_left == 0 || walls_right == 0) {
            break;
        }
        
        if (walls_left <= walls_right) { // Attack left
            int wall_pos_to_break = *walls.find_by_order(walls_left - 1);
            hamid_pos = wall_pos_to_break;
            walls.erase(wall_pos_to_break);
        } else { // Attack right
            int wall_pos_to_break = *walls.find_by_order(walls_left);
            hamid_pos = wall_pos_to_break;
            walls.erase(wall_pos_to_break);
        }
    }

    cout << days << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}