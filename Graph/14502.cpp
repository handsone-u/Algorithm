#include<iostream>
#include<queue>
using namespace std;
int n,m,b[9][9],dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1},ans,area;
bool ck[9][9];
bool pos(int x,int y){
    if(x<0||y<0||x>=n||y>=m) return false;
    return true;
}
void dfs(int x,int y){
    ck[x][y]=true;
    area++;
    for(int i=0;i<4;i++){
        int tx=x+dx[i], ty=y+dy[i];
        if(!pos(tx,ty)) continue;
        if(ck[tx][ty]) continue;
        if(b[tx][ty]==0) {
            dfs(tx,ty);
        }
    }
}
void bfs(){
    area=0;
    queue<pair<int,int> > q;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) if(b[i][j]==2) q.push(make_pair(i,j));
    while(!q.empty()){
        int tx = q.front().first, ty = q.front().second;
        q.pop();
        if(ck[tx][ty]) continue;
        dfs(tx,ty);
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) if(b[i][j]==1) area++;
    int tmp = n*m - area;
    if(tmp>ans)
        ans = tmp;
}
void makew(int x,int y,int cnt){
    b[x][y]=1;
    if(cnt==3){
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++) ck[i][j]=false;
        bfs();
        b[x][y]=0;
        return;
    }
    for(int i=x;i<n;i++)
        for(int j=0;j<m;j++){
            if(b[i][j]!=0) continue;
            makew(i,j,cnt+1);
        }
    b[x][y]=0;
}
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) cin>>b[i][j];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            if(b[i][j]!=0) continue;
            b[i][j]=1;
            makew(i,j,1);
            b[i][j]=0;
        }
    cout<<ans<<'\n';
    return 0;
}