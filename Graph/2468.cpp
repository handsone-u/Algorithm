#include<iostream>
using namespace std;
int n,map[101][101],dx[4]={1,0,-1,0},dy[4]={0,1,0,-1},ans;
bool ck[101][101];
bool pos(int x,int y){
    if(x<0||y<0||x>=n||y>=n) return false;
    if(ck[x][y]) return false;
    return true;
}
void dfs(int x,int y){
    ck[x][y]=true;
    for(int i=0;i<4;i++){
        int tx=x+dx[i], ty=y+dy[i];
        if(!pos(tx,ty)) continue;
        dfs(tx,ty);
    }
}
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    int r = 0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            cin>>map[i][j];
            if(r<map[i][j]) r=map[i][j];
        }
    ans=1;
    for(int i=1;i<r;i++){
        int tmp = 0;
        for(int x=0;x<n;x++)
            for(int y=0;y<n;y++){
                if(map[x][y]<=i) ck[x][y]=true;
                else ck[x][y]=false;
            }
        // init
        for(int x=0;x<n;x++)
            for(int y=0;y<n;y++){
                if(ck[x][y]) continue;
                tmp++;
                dfs(x,y);
            }
        if(tmp>ans) ans=tmp;
    }
    cout<<ans<<'\n';
    return 0;
}