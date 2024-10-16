#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    bool cond=true;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
     long long sum=0;
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        sum+=a[i];
    }

      if(sum%2==0 && a[n-1]<=sum/2){
        cout<<"YES";
      }else{
        cout<<"NO";
      }
    
    return 0;
}