#include<iostream>
using namespace std;
int n,a[501][501],ans,dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int dp[501][501];
bool ck[501][501];
bool pos(int x,int y){
    if(x<0||y<0||x>=n||y>=n) return false;
    return true;
}
int dfs(int x,int y){
    if(dp[x][y]) return dp[x][y];
    int dis = 0;
    for(int i=0;i<4;i++){
        int tx=x+dx[i], ty=y+dy[i];
        if(!pos(tx,ty)) continue;
        if(a[tx][ty]<=a[x][y]) continue;
        int tmp = 0;
        if(ck[x][y])
            tmp = 1+dp[x][y];
        else
            tmp = 1+dfs(tx,ty);
        if(tmp>dis) dis=tmp;
    }
    ck[x][y]=true;
    dp[x][y]=dis;
    return dp[x][y];
}
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
        cin>>a[i][j];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            if(ck[i][j]) continue;
            dp[i][j] = dfs(i,j);
            if(dp[i][j]>ans) ans=dp[i][j];
        }

    cout<<ans+1<<'\n';
    return 0;
}