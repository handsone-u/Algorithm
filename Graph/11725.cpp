#include<iostream>
#include<vector>
using namespace std;
int n,parent[100001];
vector<int> v[100001];
void dfs(int node){
    int size = v[node].size();
    for(int i=0;i<size;i++){
        int next = v[node][i];
        if(parent[next]) continue;
        parent[next] = node;
        dfs(next);
    }
}
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(int i=0;i<n-1;i++){
        int node1,node2;
        cin>>node1>>node2;
        v[node1].push_back(node2);
        v[node2].push_back(node1);
    }
    parent[1]=0;
    dfs(1);
    for(int i=2;i<=n;i++) cout<<parent[i]<<'\n';
    return 0;
}