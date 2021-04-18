#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define INF 1e9
using namespace std;
int v1,v2,n,e,tov[801], fromv1[801], fromv2[801];
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    priority_queue<pair<int ,int> >pq;
    vector<pair<int,int> >v[801];
    cin>>n>>e;
    for(int i=0;i<e;i++){
        int a,b,c; cin>>a>>b>>c;
        v[a].push_back(make_pair(b,c));
        v[b].push_back(make_pair(a,c));
    }
    cin>>v1>>v2;
    fill_n(tov, n+1, INF);
    fill_n(fromv1, n+1, INF);
    fill_n(fromv2, n+1, INF);
    pq.push(make_pair(0, 1));
    while (!pq.empty()) {
        int distance = -pq.top().first;
        int now = pq.top().second; pq.pop();
        if(tov[now]<distance) continue;
        int nsize = v[now].size();
        for(int i=0;i<nsize;i++){
            int next = v[now][i].first;
            int candi = v[now][i].second+distance;
            if(tov[next]>candi){
                tov[next]=candi;
                pq.push(make_pair(-candi, next));
            }
        }
    }
    pq.push(make_pair(0, v1));
    while (!pq.empty()) {
        int distance = -pq.top().first;
        int now = pq.top().second; pq.pop();
        if(fromv1[now]<distance) continue;
        int nsize = v[now].size();
        for(int i=0;i<nsize;i++){
            int next = v[now][i].first;
            int candi = v[now][i].second+distance;
            if(fromv1[next]>candi){
                fromv1[next]=candi;
                pq.push(make_pair(-candi, next));
            }
        }
    }
    pq.push(make_pair(0, v2));
    while (!pq.empty()) {
        int distance = -pq.top().first;
        int now = pq.top().second; pq.pop();
        if(fromv2[now]<distance) continue;
        int nsize = v[now].size();
        for(int i=0;i<nsize;i++){
            int next = v[now][i].first;
            int candi = v[now][i].second+distance;
            if(fromv2[next]>candi){
                fromv2[next]=candi;
                pq.push(make_pair(-candi, next));
            }
        }
    }
    bool f1 = true, f2 = true;
    tov[1]=fromv1[v1]=fromv2[v2]=0;
    int ans = min(tov[v1]+fromv1[v2]+fromv2[n], tov[v2]+fromv2[v1]+fromv1[n]);
    if(tov[v1]==INF||fromv1[v2]==INF||fromv2[n]==INF) f1=false;
    if(tov[v2]==INF||fromv2[v1]==INF||fromv1[n]==INF) f2=false;
    if(f1||f2) cout<<ans;
    else cout<<-1;
    return 0;
}