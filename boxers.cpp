#include <bits/stdc++.h>
using namespace std;
int main()
{
         int n;
         cin>>n;
         vector<int> a(n);
         for(int i=0;i<n;i++) cin>>a[i];
         int ans=0;
         vector<int> numbers(150002,0);
         sort(a.begin(), a.end());
         for(int i=0;i<n;i++){
            if(a[i]-1>0 && numbers[a[i]-1]==0){
                numbers[a[i]-1]=1;
                ans++;
            }else{
                if(numbers[a[i]]==0){
                    numbers[a[i]]=1;
                    ans++;
                }
                else if(numbers[a[i]+1]==0){
                    numbers[a[i]+1]=1;
                    ans++;
                }
            }

         }
        
        cout<<ans<<endl;
}