#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, a, b;
        cin >> n >> a >> b;
        bool done = false;

        // First check: if (n-1) % b == 0
        if ((n - 1) % b == 0) {
            done = true;
        } else {
            // If a == 1, we can directly check the condition (n-1) % b == 0.
            if (a == 1) {
                if ((n - 1) % b == 0) {
                    done = true;
                }
            } else {
                // Repeatedly square a and check the condition
                long long current_a = a;
                while (current_a <= n) {
                    if ((n - current_a) % b == 0) {
                        done = true;
                        break;
                    }
                    // Avoid overflow and unnecessary iterations
                    if (current_a > n / a) break;  // To avoid multiplying beyond n
                    current_a *= a;
                }
            }
        }

        // Output result
        if (done) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
