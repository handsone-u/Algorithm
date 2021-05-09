#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#define INF 1e9
using namespace std;
int d[1001],v[1001];

void transpose(vector<vector<int> > &tr, int now){
    for(int i=0;i<tr.size();i++){
        if(tr[i][0]==now){
            tr[i][0]=tr[i][1];
            tr[i][1]=now;
        }
        if(tr[i][1]==now){
            tr[i][1]=tr[i][0];
            tr[i][0]=now;
        }
    }
}

int solution(int n, int start, int end, vector<vector<int> > roads, vector<int> traps) {
    int answer = INF, rsize = roads.size(), tsize = traps.size();
    priority_queue<pair<int, int> > pq;

    fill_n(d, n+1, INF);
    d[start]=0;
    pq.push(make_pair(0, start));

    while (!pq.empty()){
        int distance = -pq.top().first, now = pq.top().second;
        pq.pop();
        v[now]++;

        if(now==end) continue;
        cout<<now<<' '<<distance<<' '<<v[now]<<endl;

        if(distance>d[now]||!v[now]==2) {
            continue;
        }
        cout<<now<<' '<<distance<<endl;
        for(int i=0;i<tsize;i++){
            if(now==traps[i]){
                transpose(roads, now);
                break;
            }
        }

        for(int i=0;i<rsize;i++){
            if(roads[i][0]!=now) continue;
            int adddist = distance+roads[i][2];
            pq.push(make_pair(-adddist, roads[i][1]));
            if(d[roads[i][1]]>adddist)
                d[roads[i][1]] = adddist;
        }
    }

    answer = d[end];

    return answer;
}