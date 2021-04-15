#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define INF 1e9
using namespace std;
int v,e,k,d[20001];
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>v>>e>>k;
    fill_n(d,v+1,INF);
    priority_queue<pair<int, int> > pq;
    vector<pair<int ,int> > node[20001];
    for(int i=0;i<e;i++){
        int u,v,w; cin>>u>>v>>w;
        node[u].push_back(make_pair(v,w));
    }
    d[k]=0;
    pq.push(make_pair(0, k));
    while(!pq.empty()){
        int now = pq.top().second;
        int dis = -pq.top().first; pq.pop();
        if(dis>d[now]) continue;
        int nsize = node[now].size();
        for(int i=0;i<nsize;i++){
            int next = node[now][i].first;
            int val = node[now][i].second;
            if(d[next]>val+dis){
                d[next]=val+dis;
                pq.push(make_pair(-d[next], next));
            }
        }
    }
    for(int i=1;i<=v;i++)
        if(d[i]==INF) cout<<"INF\n";
        else cout<<d[i]<<'\n';
    return 0;
}