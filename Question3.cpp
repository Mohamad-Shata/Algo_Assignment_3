// Question 3: Bank Robbery
#include <tuple>
#include <iostream>
#include <string>
#include <cmath>
#include <vector>


using namespace std;

int knapsack(int capacity, vector<pair<int, int>>& items) {
    vector<int> dp(capacity + 1, 0);

    for (auto& [weight, value] : items) {
        for (int j = capacity; j >= weight; --j) {
            dp[j] = max(dp[j], dp[j - weight] + value);
        }
    }
    return dp[capacity];
}

void testKnapsack() {
    vector<pair<int, vector<pair<int, int>>>> testCases = {
        {34, {{13, 7}, {30, 1}, {34, 8}}},
        {50, {{10, 60}, {20, 100}, {30, 120}}},
        {10, {{5, 10}, {4, 40}, {6, 30}}}
    };

    for (auto& [capacity, items] : testCases) {
        cout << "Maximum value for capacity " << capacity << ": " << knapsack(capacity, items) << endl;
    }
}

int main() {
    // Test Question 3
    cout << "\nTesting Knapsack..." << endl;
    testKnapsack();

    return 0;
}