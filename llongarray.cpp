#include <iostream>
#include <cstdint>
#include <limits>
#include <cstdlib>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--) {
        std::uint64_t n, k;
        std::cin >> n >> k;

        // Calculate T using the formula
        std::uint64_t T = (n * (2 * k + n - 1)) / 2;
        std::uint64_t minDiff = std::numeric_limits<std::uint64_t>::max();

        // Use binary search to find the optimal value of i
        std::uint64_t KK = 2 * k - 1;
        std::uint64_t low = n / 2;
        std::uint64_t high = n;
        while (low <= high) {
            std::uint64_t mid = (low + high) / 2;
            std::uint64_t midn = mid * (KK + mid);
            std::uint64_t diff = (T > midn) ? (T - midn) : (midn - T);
            if (diff < minDiff) {
                minDiff = diff;
            }
            if (midn < T) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        std::cout << minDiff << std::endl; // Output the result for the test case
    }

    return 0;
}