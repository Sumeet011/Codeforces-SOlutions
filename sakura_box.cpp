#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1e9 + 7;

// Function to compute the modular inverse of 'a' modulo 'mod' using Fermat's Little Theorem
long long modInverse(long long a, long long mod) {
    long long result = 1, base = a, exponent = mod - 2;
    while (exponent > 0) {
        if (exponent % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exponent /= 2;
    }
    return result;
}

int main() {
    int t;
    cin >> t; // Number of test cases

    while (t--) {
        int n;
        cin >> n; // Size of array

        vector<long long> arr(n);
        long long sum = 0;        // Sum of all elements
        long long sumOfSquares = 0; // Sum of squares of all elements

        for (int i = 0; i < n; i++) {
            cin >> arr[i]; // Input elements of the array
            sum = (sum + arr[i]) % MOD; // Update sum modulo MOD
            sumOfSquares = (sumOfSquares + (arr[i] * arr[i]) % MOD) % MOD; // Update sumOfSquares modulo MOD
        }

        // Calculate P = (sum * sum - sumOfSquares) / 2 % MOD
        long long sumSquared = (sum * sum) % MOD; // Calculate sum * sum modulo MOD
        long long P = (sumSquared - sumOfSquares + MOD) % MOD; // Ensure positive result
        P = (P * modInverse(2, MOD)) % MOD; // Divide by 2 using modular inverse

        // Calculate Q = n * (n - 1) / 2 % MOD
        long long Q = ((static_cast<long long>(n) * (n - 1)) % MOD * modInverse(2, MOD)) % MOD;

        // Compute Q^-1 modulo MOD
        long long Q_inverse = modInverse(Q, MOD);

        // Compute P * Q^-1 % MOD
        long long result = (P * Q_inverse) % MOD;

        // Output the result for this test case
        cout << result << endl;
    }

    return 0;
}
