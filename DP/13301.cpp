#include <iostream>
long long dp[81];
using namespace std;
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    dp[1]=1;
    dp[2]=1;
    int n;
    cin>>n;
    for(int i=3;i<=n;i++)
        dp[i]=dp[i-1]+dp[i-2];
    cout<<dp[n]*2+(dp[n]+dp[n-1])*2<<'\n';
    return 0;
}