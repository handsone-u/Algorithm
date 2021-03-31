#include<iostream>
using namespace std;
int n,m,a[42],dp[42],ans=1;
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=40;i++) dp[i]=dp[i-1]+dp[i-2];
    for(int i=1;i<=m;i++) cin>>a[i];
    a[m+1]=n+1;
    for(int i=1;i<=m+1;i++){
        int gap = a[i]-a[i-1]-1;
        if(gap==0) continue;
        ans*=dp[gap];
    }
    cout<<ans<<'\n';
    return 0;
}