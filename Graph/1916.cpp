#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define INF 1e9
using namespace std;
int n,m,d[1001],a,b;
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<pair<int, int> > node[1001];
    priority_queue<pair<int,int> > pq;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w; cin>>u>>v>>w;
        node[u].push_back(make_pair(v,w));
    }
    fill_n(d, n+1, INF);
    cin>>a>>b;
    d[a]=0; pq.push(make_pair(d[a], a));
    while(!pq.empty()){
        int now = pq.top().second;
        int dist = -pq.top().first; pq.pop();
        if(dist > d[now]) continue;
        int nsize = node[now].size();
        for(int i=0;i<nsize;i++){
            int next = node[now][i].first;
            int val = node[now][i].second;
            if(d[next]>val+dist){
                d[next]=val+dist;
                pq.push(make_pair(-d[next], next));
            }
        }
    }
    cout<<d[b];
    return 0;
}