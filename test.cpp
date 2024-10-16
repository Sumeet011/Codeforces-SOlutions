#include<bits/stdc++.h>
using namespace std;
int main(){
    
    long long num;
    cin>>num;
    vector<int> number;
    int i=-1;
    while(num>0){
        number.push_back(num%10);
        num/=10;
        i++;
        if(num<=0){
            if(9-number[i]<number[i] && 9-number[i]!=0){
                  number[i]=9-number[i];
            }
        }else{
            if(9-number[i]<number[i]){
                number[i]=9-number[i];
            }
        }
    }
    reverse(number.begin(), number.end());
    long long ans=0;
    for(int i=0; i<number.size(); i++){
        ans=ans*10+number[i];
    }
    cout<<ans<<endl;
}
