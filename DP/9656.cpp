#include<iostream>
using namespace std;
int n,dp[1004];
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    dp[1]=dp[3]=1;
    for(int i=1;i<=n;i++){
        if(dp[i]==1) {
            dp[i+1] =2;
            dp[i+3] =2;
        }
        else {
            dp[i+1] = 1;
            dp[i+3] = 2;
        }
    }
    dp[n-1]==1 ? cout<<"SK" : cout<<"CY";
    return 0;
}