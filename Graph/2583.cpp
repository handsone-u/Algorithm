#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1},cnt,m,n,a[101][101];
void dfs(int y,int x){
    a[y][x]=1;
    cnt++;
    for(int i=0;i<4;i++){
        int tx = dx[i]+x, ty = dy[i]+y;
        if(tx<0||ty<0||tx>=n||ty>=m) continue;
        if(a[ty][tx]) continue;
        dfs(ty,tx);
    }
}
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<int> v;
    int k;
    cin>>m>>n>>k;
    for(int i=0;i<k;i++){
        int x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        for(int y=y1;y<y2;y++)
            for(int x=x1;x<x2;x++) a[y][x]=1;
    }
    for(int y=0;y<m;y++)
        for(int x=0;x<n;x++){
            if(a[y][x]) continue;
            cnt=0;
            dfs(y,x);
            v.push_back(cnt);
        }
    sort(v.begin(),v.end());
    cout<<v.size()<<'\n';
    for(auto i : v) cout<<i<<' ';
    return 0;
}