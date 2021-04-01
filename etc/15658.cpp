#include<iostream>
using namespace std;
int n,a[12],op[4],mu,le;
bool pos(int o, int cur){
    if(op[o]>=cur) return true;
    else return false;
}
void dfs(int o1, int o2,int o3, int o4,int result){
    if(o1+o2+o3+o4==n-1){
        if(result>mu) mu=result;
        if(result<le) le=result;
        return;
    }
    int p = o1+o2+o3+o4+1;
    if(pos(0,o1+1))
        dfs(o1+1,o2,o3,o4,result+a[p]);
    if(pos(1,o2+1))
        dfs(o1,o2+1,o3,o4,result-a[p]);
    if(pos(2,o3+1))
        dfs(o1,o2,o3+1,o4,result*a[p]);
    if(pos(3,o4+1))
        dfs(o1,o2,o3,o4+1,result/a[p]);
}
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<4;i++) cin>>op[i];
    mu=INT32_MIN;
    le=INT32_MAX;
    dfs(0,0,0,0,a[0]);
    // + - * /
    cout<<mu<<'\n'<<le<<'\n';
    return 0;
}