// Question 1: Fair Division of Coins
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int fairDivision(vector<int>& coins) {
    int totalSum = accumulate(coins.begin(), coins.end(), 0);
    int halfSum = totalSum / 2;
    vector<int> dp(halfSum + 1, 0);

    for (int coin : coins) {
        for (int j = halfSum; j >= coin; --j) {
            dp[j] = max(dp[j], dp[j - coin] + coin);
        }
    }
    return abs(totalSum - 2 * dp[halfSum]);
}

void testFairDivision() {
    vector<vector<int>> testCases = {
        {2, 3, 5},
        {1, 2, 4, 6},
        {10, 20, 15, 5}
    };

    for (auto& testCase : testCases) {
        cout << "Minimal difference: " << fairDivision(testCase) << endl;
    }
}

int main() {
    // Test Question 1
    cout << "Testing Fair Division..." << endl;
    testFairDivision();
    return 0;
}