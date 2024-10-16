// LINK :- https://codeforces.com/problemset/problem/2010/C1

/*⠀⠀⠀⠀⠀⠀⠀⠀⠀⣴⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⢀⣼⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⣾⡿⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡠⢤⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠸⠋⠀⠀⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⠀⣤⣤⣤⣤⣴⣤⡄⠀⠀⠀⠀⠀⢀⠄⠀⠀⠀⠂⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⠐⠂⠉⢀⣿⣿⣿⣿⣿⠟⠁⠀⠀⠀⠀⠀⠈⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠄⠂⠀⠀⠀⠀⠀⢀⣾⣿⣿⡿⠛⠁⠀⠀⠀⠀⡐⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⡀⠀⠈⠉⠁⠀⠀⠀⠉⠁⠀⠀⠊⠀⠀⠀⠀⠀⠀⠀⢀⡾⠛⠋⠁⠀⠀⠀⠀⠀⠄⠊⠀⠀⠀⠀⠀⠀⠀⠀⠀⠇
⠀⠀⠀⠀⠀⢀⡀⠁⠀⠀⠀⠀⠀⠀⣴⣘⣶⡀⠀⠀⠀⠈⠠⡀⠀⠀⠐⠈⠁⠀⠀⠀⠀⠀⠀⠀⠀⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰
⠀⠀⠀⠀⠠⣾⣡⠀⠀⡀⠀⠀⠀⠀⠻⠿⠛⠀⣀⡀⠀⠀⠀⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠊
⠀⠀⠀⠀⡀⠛⠋⣀⣀⣀⣀⣠⡔⠀⠀⠀⢠⢃⢐⡜⡦⠀⠀⠀⢣⠀⠀⠀⠀⠀⠀⠀⢀⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠏⣄⠀⠀⠀⢻⢷⣹⣾⠀⠀⠀⠸⣚⡬⢖⡓⠀⠀⠀⠀⢂⠀⠀⠀⠀⠀⠀⠈⢆⠀⠀⠀⠀⠀⠀⠀⢀⠄⠂⠁⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠘⡼⡄⠀⠀⠈⢻⡃⢸⠀⠀⠀⠀⠑⠛⠊⠀⠀⠀⠀⠀⠀⠂⠀⠀⠀⠀⠀⠀⠈⢆⠀⠀⠀⡀⠀⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠑⢇⠀⠀⠀⠈⠑⠊⠀⠀⠀⠀⠀⠀⠀⠀⣠⡄⡀⠄⠀⠐⡀⠀⠀⠀⠀⠀⠀⠘⡄⠀⢐⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⡀⠄⠀⠐⠢⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠮⠁⢿⠜⠀⠀⠀⠹⡄⠀⠀⠀⠀⢀⠠⠂⠀⠈⢦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⢀⠬⡈⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠎⠑⢧⠘⠐⠀⠀⠀⠉⢠⠀⢠⠴⠁⠀⠀⡠⠐⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠸⣅⠝⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⠄⠂⠀⠀⠀⠀⠀⠀⠀⠱⡀⠑⢄⣴⢣⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠈⠀⠀⠀⠀⠀⠒⠚⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⡄⠀⣱⣿⣷⢄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣿⡿⠗⠋⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣵⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⠂⠀⢨⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢢⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠑⢀⠤⠀⠀⠀⠀⡀⠠⠄⠀⠤⢀⠀⡀⠀⠀⠀⠀⠀⣠⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠐⣖⢮⡇⠀⠀⠀⠀⠀⠀⠀⠀⠈⠁⠈⡍⡽⡼⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠤⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠥⣡⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int l = s.length();
    int i;
    for (i = l / 2 + 1; i < l; ++i)
    {
        if (s.substr(0, i) == s.substr(l - i, i))
            break;
    }
    if (i == l)
        cout << "NO\n";
    else
    {
        cout << "YES\n";
        cout << s.substr(0, i);
    }
    return 0;
}