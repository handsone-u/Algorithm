#include<iostream>
using namespace std;
int n,dp[101][101];
void floyd(){
    for(int k=1;k<=n;k++)
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
        if(dp[i][k]&&dp[k][j]) dp[i][j]=1;
}
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) cin>>dp[i][j];
    floyd();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) cout<<dp[i][j]<<' ';
        cout<<'\n';
    }
    return 0;
}