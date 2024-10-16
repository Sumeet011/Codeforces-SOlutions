#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        long long low = n;
        long long high = 2 * n;
        long long ans = high;  // Use long long max to avoid overflow
        
        while(low <= high) {
            long long mid = (low + high) / 2;
            long long p=sqrt(mid);
            long long value = mid - p; // This is the expression you're trying to minimize
            
            if(value >= n) {  // Adjust the condition based on the problem requirements
                ans = mid ; // Keep track of the minimum mid that satisfies the condition
                high = mid - 1;       // Move left to minimize further
            } else {
                
                low = mid + 1;        // Move right to find a valid mid
            }
        }
        
        // Output the result for this test case
        cout << ans << endl;
    }
    
    return 0;
}
