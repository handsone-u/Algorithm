#include<iostream>
#include<vector>
using namespace std;
vector<int> v[32001],depth[32001];
int n,m,ck[32001];
bool topol[32001];

void dfs(int vtx, int cnt){
    ck[vtx]=cnt;
    int size = v[vtx].size();
    for(int i=0;i<size;i++){
        int next = v[vtx][i];
        if(ck[next]>=cnt+1) continue;
        dfs(next, cnt+1);
    }
}
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        topol[y]=true;
    }

    for(int i=1;i<=n;i++){
        if(topol[i]) continue;
        dfs(i,1);
    }

    for(int i=1;i<=n;i++)
        depth[ck[i]].push_back(i);

    for(int i=1;i<=n;i++){
        if(depth[i].size()==0) break;
        for(vector<int>::iterator it=depth[i].begin();it!=depth[i].end();it++) 
            cout<<*it<<' ';
    }
    return 0;
}