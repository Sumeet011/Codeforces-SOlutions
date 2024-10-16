#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int z=0;
    cin >> n; // Number of test cases
    while (n--) {
        int a, b;
        cin >> a >> b; // Length of arrays and a threshold
        vector<int> v(a);
        vector<int> v2(a);
        
        for (int i = 0; i < a; i++) {
            cin >> v[i]; // Input for the first array
        }
        
        for (int i = 0; i < a; i++) {
            cin >> v2[i]; // Input for the second array
        }

        bool istrue = true;
        
        // Check the first condition: if b == 0, arrays must be identical
        if (b == 0 && v != v2) {
            istrue = false;
        } else {
            // Find the index in v where the first element of v2 appears
            int indx = find(v.begin(), v.end(), v2[0]) - v.begin();
            if (indx == a) { // If not found
                istrue = false;
            } else {
                // Compare the rest of the elements in a circular manner
                for (int i = 0; i < a; i++) {
                    if (v[(indx + i) % a] != v2[i]) {
                        istrue = false;
                        break;
                    }
                }
            }
        }
        z++;
        cout << "Case #"<<z<<" "<<(istrue ? "YES" : "NO") << endl;
    }
    return 0;
}
