#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        long long n, k;
        cin >> n >> k;

        // Special case where k = 1, all powers of k are 1, so we need n terms of 1
        if (k == 1) {
            cout << n << "\n";
            continue;
        }

        long long ans = 0;
        
        // Precompute powers of k and store them in a vector
        vector<long long> powers;
        long long power = 1;
        
        // Generate all powers of k that are less than or equal to n
        while (power <= n) {
            powers.push_back(power);
            if (power > LLONG_MAX / k) break; // To prevent overflow
            power *= k;
        }

        // Traverse powers from the largest to the smallest
        int idx = powers.size() - 1;
        while (n > 0) {
            // Find the largest power of k less than or equal to n
            if (powers[idx] <= n) {
                if(n%powers[idx]==0){
                    ans+=n/powers[idx];
                    n-=((n/powers[idx])*powers[idx]);
                }
                else{
                      int d=n/powers[idx];
                      ans+=d;
                      n-=(d*powers[idx]);
                }
            } else {
                idx--;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
