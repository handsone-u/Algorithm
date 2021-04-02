#include<iostream>
using namespace std;
int n,ans,dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};
char map[101][101];
bool ck[101][101];
bool pos(int x,int y){
    if(x<0||y<0||x>=n||y>=n) return false;
    return true;
}
void dfs(int x,int y,char col){
    for(int i=0;i<4;i++){
        int tx=x+dx[i], ty=y+dy[i];
        if(!pos(tx,ty)) continue;
        if(ck[tx][ty]) continue;
        if(col!=map[tx][ty]) continue;
        ck[tx][ty]=true;
        dfs(tx,ty,col);
    }
}
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) cin>>map[i][j];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            if(ck[i][j]) continue;
            ans++;
            dfs(i,j,map[i][j]);
        }
    cout<<ans<<' ';
    ans=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            ck[i][j]=false;
            if(map[i][j]=='R') map[i][j]='G';
        }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            if(ck[i][j]) continue;
            ans++;
            dfs(i,j,map[i][j]);
        }
    cout<<ans<<'\n';
    return 0;
}