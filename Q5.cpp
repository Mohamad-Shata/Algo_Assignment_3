#include <iostream>
#include <vector>
#include <algorithm> // For max function
using namespace std;

int longestIncreasingSubsequenceLength(vector<int>& A) {
    int N = A.size();
    vector<int> dp(N, 1); // Initialize dp array with 1s

    // Fill the dp array
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (A[i] > A[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    // Find the maximum value in dp array
    int maxLength = 0;
    for (int i = 0; i < N; i++) {
        if (dp[i] > maxLength) {
            maxLength = dp[i];
        }
    }

    return maxLength;
}

int main() {
    // Input
    int N;
    cin >> N; // Read the length of the list
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i]; // Read the numbers in the list
    }

    // Output
    cout << longestIncreasingSubsequenceLength(A) << endl;

    return 0;
}
