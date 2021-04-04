#include<iostream>
using namespace std;
int n,a[501][501],ans,dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
// hello
bool ck[501][501];
bool pos(int x,int y){
    if(x<0||y<0||x>=n||y>=n) return false;
    return true;
}
void initck(){
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++) ck[i][j]=false;
}
void dfs(int x,int y,int tmp){
    ck[x][y]=true;
    if(tmp>ans) ans=tmp;
    for(int i=0;i<4;i++){
        int tx=x+dx[i], ty=dy[i];
        if(!pos(tx,ty)) continue;
        if(ck[tx][ty]) continue;
        if(a[tx][ty]<=a[x][y]) continue;
        dfs(tx,ty,tmp+1);
    }
    ck[x][y]=false;
}
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++) cin>>a[i][j];

    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++){
        initck();
        dfs(i,j,1);
    }

    cout<<ans<<'\n';
}