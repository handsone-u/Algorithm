#include<iostream>
using namespace std;
int n,m,a[301][301],dx[4]={1,0,-1,0},dy[4]={0,1,0,-1},ans,tot;
bool ck[301][301],melted[301][301];
void dfs(int x,int y){
    ck[x][y]=true;
    for(int i=0;i<4;i++){
        int tx=x+dx[i], ty=y+dy[i];
        if(a[tx][ty]==0) continue;
        if(ck[tx][ty]) continue;
        dfs(tx,ty);
    }
}
int melt(int x,int y){
    int cur = a[x][y];
    int cnt=0;
    for(int i=0;i<4;i++){
        int tx=x+dx[i], ty=y+dy[i];
        if(melted[tx][ty]) continue;
        if(a[tx][ty]!=0)  continue;
        cnt++;
        if(cnt>=cur) {
            melted[x][y]=true;
            break;
        }
    }
    tot-=cnt;
    return cur-cnt;
}
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++) {
        cin>>a[i][j];
        tot+=a[i][j];
    }
    while(tot>0){
        int isl = 0;
        for(int i=1;i<n;i++)
        for(int j=1;j<m;j++)
            if(a[i][j]){
                if(ck[i][j]) continue;
                isl++;
                dfs(i,j);
            }
        if(isl>=2) break;
        else ans++;
        for(int i=1;i<n;i++)
        for(int j=1;j<m;j++) ck[i][j]=melted[i][j]=false;
        for(int i=1;i<n;i++)
        for(int j=1;j<m;j++){
            if(a[i][j]==0) continue;
            a[i][j]=melt(i,j);
        }
    }
    if(tot==0) ans=0;
    cout<<ans<<'\n';
    return 0;
}