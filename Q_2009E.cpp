#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

void solve() {
    long long n, k;
    cin >> n >> k;

    // Calculate total sum T
    long long totalSum = (n * (2 * k + (n - 1))) / 2; // Total sum of the array

    // Potential x1 and x2 can be computed based on the quadratic vertex formula
    long long x1 = abs((1 - 2 * k) / 2);  // Evaluate for index 1
    long long x2 = abs((n - 1 - 2 * k) / 2); // Evaluate for index n

    // Calculate the quadratic values and take their absolute differences from T
    long long ans = min(
        abs((x1 * x1) + ((2 * k - 1) * x1) - totalSum),
        abs((x2 * x2) + ((2 * k - 1) * x2) - totalSum)
    );

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read number of test cases
    while (t--) {
        solve();
    }
    return 0;
}
