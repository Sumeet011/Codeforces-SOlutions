#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<char> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        
        int blanks = 0;
        for (int i = 0; i < n; i++) {
            if (i < n - 2 && v[i] == '.' && v[i + 1] == '.' && v[i + 2] == '.') {
                blanks = 2;  // Count 3 consecutive dots as 2 blanks
                break;   // Skip the next two dots as they're already counted
            } else if (v[i] == '.') {
                blanks++;      // Count single dots as 1 blank
            }
        }
        cout << blanks << endl;
    }
}
