#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        if(a==1 && b==1){
            cout<<"0\n";
        }
        else{
            cout<<(min(a,b)*2)+(max(a,b)-2)<<"\n";
        }
    }
}
