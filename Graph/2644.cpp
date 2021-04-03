#include<iostream>
#include<vector>
using namespace std;
int n,a,b,m,ans;
vector<int> v[101];
bool ck[101];
void dfs(int node,int cnt){
    if(node==b){
        ans = cnt;
        return;
    }
    int vsize = v[node].size();
    for(int i=0;i<vsize;i++){
        int tnode = v[node][i];
        if(ck[tnode]) continue;
        ck[tnode]=true;
        dfs(tnode,cnt+1);
    }
}
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n>>a>>b>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    ck[a]=true;
    dfs(a,0);
    ans==0 ? cout<<-1 : cout<<ans;
    cout<<'\n';
    return 0;
}