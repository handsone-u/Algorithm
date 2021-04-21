#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
int par[101];
int find_u(int node){
    if(par[node]!=node)
        par[node]=find_u(par[node]);
    return par[node];
}
void union_add(int a,int b){
    a = find_u(a);
    b = find_u(b);
    if(a<b)
        par[b]=a;
    else
        par[a]=b;
}
int solution(int n, vector<vector<int> > costs) {
    int answer = 0, m = costs.size();
    priority_queue<pair<int, pair<int, int> > > pq;
    for(int i=0;i<n;i++) par[i]=i;
    for(int i=0;i<m;i++)
        pq.push(make_pair(-costs[i][2],make_pair(costs[i][0],costs[i][1])));
    while(!pq.empty()){
        int val = pq.top().first;
        int fir = pq.top().second.first;
        int sec = pq.top().second.second;
        pq.pop();
        if(find_u(fir)==find_u(sec)) continue;
        answer-=val;
        union_add(fir, sec);
    }
    return answer;
}