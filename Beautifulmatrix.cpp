#include<bits/stdc++.h>
using namespace std;
int main() {
    int Row=0,Colum=0,ans=0;
    for(int i=1;i<=5;i++){
        for(int j=1;j<=5;j++){
            int n;
            cin>>n;
            if(n==1){
              ans=abs(3-i)+abs(3-j);
              break;
            }
        }
    }
    cout<<ans<<endl;
}

