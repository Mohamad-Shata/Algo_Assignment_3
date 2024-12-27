// Question 2: Original Message Possibilities
#include <iostream>
#include <string>
#include <unordered_map>
#include <cmath>
#include <vector>


using namespace std;

const int MOD = 1e9 + 7;

int countPossibilities(string& s) {
    unordered_map<char, int> transformations = {{'w', 2}, {'m', 2}};
    long long possibilities = 1;

    for (char c : s) {
        if (transformations.count(c)) {
            possibilities = (possibilities * transformations[c]) % MOD;
        }
    }
    return possibilities;
}

void testCountPossibilities() {
    vector<string> testCases = {"ouuoharinn", "banana", "nnn", "amanda"};

    for (auto& testCase : testCases) {
        cout << "Possibilities for '" << testCase << "': " << countPossibilities(testCase) << endl;
    }
}

int main() {
    // Test Question 2
    cout << "\nTesting Original Message Possibilities..." << endl;
    testCountPossibilities();

    return 0;
}