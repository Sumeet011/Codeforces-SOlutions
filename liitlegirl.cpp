#include <bits/stdc++.h>
using namespace std;

int main() {
    // Input reading
    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Frequency array to count how many times each index is accessed
    vector<int> freq(n, 0);

    // Process the queries using the difference array technique
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        l--; r--; // Convert to 0-based indexing

        freq[l]++; // Start of range increment
        if (r + 1 < n) {
            freq[r + 1]--; // End of range increment
        }
    }

    // Apply the prefix sum to get the actual frequency of each index
    for (int i = 1; i < n; ++i) {
        freq[i] += freq[i - 1];
    }

    // Sort the frequency array and the original array in descending order
    sort(freq.begin(), freq.end(), greater<int>());
    sort(arr.begin(), arr.end(), greater<int>());

    // Compute the maximum sum by assigning the largest elements to the most frequent indices
    long long max_sum = 0;
    for (int i = 0; i < n; ++i) {
        max_sum += (long long)arr[i] * freq[i];
    }

    // Output the result
    cout << max_sum << endl;

    return 0;
}
