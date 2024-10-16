#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, r;
        cin >> n >> r;
        int happy_persons = 0;  
        int unhappy_persons = 0;
        while (n--)
        {
            int a;
            cin >> a;
            happy_persons += (a / 2) * 2;
            unhappy_persons += a % 2;
            r -= a / 2;
        }
        if (r >= unhappy_persons)
        {
            cout << happy_persons + unhappy_persons << endl;
        }
        else
        {
            while (unhappy_persons > 0)
            {
                if (r >= unhappy_persons)
                {
                    happy_persons += unhappy_persons;
                    break;
                }
                else
                {
                    unhappy_persons -= 2;
                    r--;
                }
            }
            cout << happy_persons << endl;
        }
    }
}