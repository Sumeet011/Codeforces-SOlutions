#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        while(q--){

            long long sum=0;
            int rotation=0;
            int l,r;
            cin>>l>>r;
            l--,r--;
            long long Length=n;
            while(l<=r){
                while(l<Length){
                    int i=l%n;
                    sum+=a[(i+rotation)%Length];
                    l++;
                }
                    Length+=n;
                    rotation++;    
            }
            


            cout<<sum<<endl;
            Length=n;
        }
    }
    return 0;
 
}