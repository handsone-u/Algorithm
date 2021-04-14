#include<iostream>
using namespace std;
int n,ans,dp[17][17][3];
bool ck[17][17];
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>ck[i][j];

    for(int i=2;i<=n;i++) {
        if(ck[1][i]) break;
        dp[1][i][0]=1;
        if(ck[1][i-1]) dp[1][i][0]=0;
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(ck[i][j]){
                dp[i][j][0]=dp[i][j][1]=dp[i][j][2]=0;
                continue;
            }
            dp[i][j][0]=dp[i][j-1][0]+dp[i][j-1][1];
            dp[i][j][1]=dp[i-1][j-1][0]+dp[i-1][j-1][1]+dp[i-1][j-1][2];
            dp[i][j][2]=dp[i-1][j][1]+dp[i-1][j][2];
            if(ck[i-1][j]||ck[i][j-1]) dp[i][j][1]=0;
        }
    }
    for(int i=0;i<3;i++)
        ans += dp[n][n][i];
    cout<<ans;
    return 0;
}
