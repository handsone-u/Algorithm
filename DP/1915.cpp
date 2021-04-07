#include<iostream>
#include<algorithm>
using namespace std;
int n,m,ans,dp[1000][1000];
char a[1000][1000];
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) cin>>a[i][j];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            if(a[i][j]=='0') continue;
            if(i==0||j==0) dp[i][j]=1;
            else
                dp[i][j]=min({dp[i-1][j],dp[i-1][j-1],dp[i][j-1]})+1;
            if(dp[i][j]>ans) ans=dp[i][j];
        }
     ans*=ans;
     cout<<ans<<'\n';
    return 0;
}