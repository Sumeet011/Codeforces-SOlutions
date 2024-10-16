#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;

int modular_exponentiation(int base, int exponent, int modulus) 
{
    int result = 1;
    while (exponent > 0) 
    {
        if (exponent % 2 == 1) 
        {
            result = (result * base) % modulus;
        }
        
        base = (base * base) % modulus; 
        exponent /= 2;
    }
    
    return result;
}

int32_t main() 
{
    int test_cases;
    cin >> test_cases;

    vector<int> n_values(test_cases), k_values(test_cases);

    // Read n values
    for (int i = 0; i < test_cases; ++i) 
    {
        cin >> n_values[i];
    }

    // Read k values
    for (int i = 0; i < test_cases; ++i) 
    {
        cin >> k_values[i];
    }

    // Calculate results for each test case
    for (int i = 0; i < test_cases; i++)
    {
        cout << modular_exponentiation(2, k_values[i], MOD) << endl;
    }

    return 0;
}
