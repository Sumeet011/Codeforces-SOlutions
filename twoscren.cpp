#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s, t;
        cin >> s >> t;
        int i = 0;
        int time = 0;
        while(i<min(s.length(),t.length()) && s.at(i)==t.at(i)){
            i++;
            time++;
        }
        if(time>0){
            time++;
        }
        int j=i;
        while(j<s.length()){
            time++;
            j++;
        }
        while(i<t.length()){
            time++;
            i++;
        }
        
        cout<<time<<endl;
    }
}