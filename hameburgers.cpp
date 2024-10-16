#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int nb, ns, nc;   // Initial quantities of B, S, C
    int pb, ps, pc;   // Prices of B, S, C
    long long Total;  // Total money available
    cin >> s >> nb >> ns >> nc >> pb >> ps >> pc >> Total;
    
    long long cb = 0, cs = 0, cc = 0;  // Count ingredients required per hamburger
    for (char ch : s)
    {
        if (ch == 'B') cb++;
        if (ch == 'S') cs++;
        if (ch == 'C') cc++;
    }
    
    long long L = 0, R = Total + nb + ns + nc, mid, ans = 0;

    while (L <= R)
    {
        mid = (L + R) / 2;
        long long fx = max(0LL, cb * mid - nb) * pb +
                       max(0LL, cs * mid - ns) * ps +
                       max(0LL, cc * mid - nc) * pc;
        
        if (fx <= Total)
        {
            ans = mid;  // Mid is valid, try for more
            L = mid + 1;
        }
        else
        {
            R = mid - 1;
        }
    }
    
    cout << ans << endl;
    return 0;
}
