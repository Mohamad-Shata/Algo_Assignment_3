#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to maximize the gold recovered
void maximizeGold(int t, int w, vector<pair<int, int>>& treasures) {
    int n = treasures.size();
    // Calculate the total time for each treasure
    vector<int> times;
    vector<int> values;
    for (auto& treasure : treasures) {
        int d = treasure.first;
        int v = treasure.second;
        times.push_back(3 * w * d); // Total time for this treasure
        values.push_back(v);
    }

    // Initialize DP table
    vector<vector<int>> dp(n + 1, vector<int>(t + 1, 0));

    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= t; j++) {
            if (times[i - 1] <= j) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - times[i - 1]] + values[i - 1]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // Backtrack to find the selected treasures
    vector<pair<int, int>> selected;
    int j = t;
    for (int i = n; i > 0; i--) {
        if (dp[i][j] != dp[i - 1][j]) {
            selected.push_back(treasures[i - 1]);
            j -= times[i - 1];
        }
    }

    // Reverse to maintain the original order
    reverse(selected.begin(), selected.end());

    // Output the results
    cout << dp[n][t] << endl; // Maximum gold
    cout << selected.size() << endl; // Number of selected treasures
    for (auto& treasure : selected) {
        cout << treasure.first << " " << treasure.second << endl; // Selected treasures
    }
    cout << endl; // Blank line between test cases
}

int main() {
    int t, w, n;
    while (cin >> t >> w) {
        cin >> n;
        vector<pair<int, int>> treasures;
        for (int i = 0; i < n; i++) {
            int d, v;
            cin >> d >> v;
            treasures.push_back({d, v});
        }
        // Process the test case
        maximizeGold(t, w, treasures);
    }
    return 0;
}
