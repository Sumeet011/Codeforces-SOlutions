#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i];
        }

        long long MAX = *max_element(a.begin(), a.end());

        // Proper ceil with floating-point division
        long long customer = max(static_cast<long long>(ceil(sum / static_cast<double>(k))), MAX);

        cout << customer << endl;
    }
}
