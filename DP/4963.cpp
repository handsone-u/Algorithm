#include <iostream>
using namespace std;
int w,h,ans,a[51][51],dx[8]={1,0,-1,0,1,1,-1,-1},dy[8]={0,1,0,-1,1,-1,1,-1};

void dfs(int x,int y){
    a[x][y]=0;
    for(int i=0;i<8;i++){
        int tx,ty;
        tx = x+dx[i];
        ty = y+dy[i];
        if(tx<0||ty<0||tx>=h||ty>=w) continue;
        if(a[tx][ty]==1) dfs(tx,ty);
    }
}

int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while(true){
        ans = 0;
        cin>>w>>h;
        if(w==h&&w==0) break;
        for(int i=0;i<h;i++)
            for(int j=0;j<w;j++) cin>>a[i][j];
        for(int i=0;i<h;i++)
            for(int j=0;j<w;j++){
                if(a[i][j]==1){
                    ans++;
                    dfs(i,j);
                }
            }
        cout<<ans<<'\n';
    }
    return 0;
}