#include<iostream>
using namespace std;
int n,a[101][101];
long long dp[101][101];
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) cin>>a[i][j];
    dp[0][0]=1;
    for(int i=0;i<n; i++){
        for(int j=0;j<n;j++){
            if(!dp[i][j]) continue;
            int tmp1 = i+a[i][j];
            int tmp2 = j+a[i][j];
            if(i==j&&i==n-1) break;
            if(tmp2<n) dp[i][tmp2]+=dp[i][j];
            if(tmp1<n) dp[tmp1][j]+=dp[i][j];
        }
    }
    cout<<dp[n-1][n-1]<<'\n';
    return 0;
}