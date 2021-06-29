#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

class Abc {
public:
    int x,y,z;

    Abc(int xt,int yt,int zt) {
        x=xt;
        y=yt;
        z=zt;
    }
};

struct cmp {
    bool operator()(Abc a, Abc b) {
        if(a.x==b.x){
            if(a.z==b.z)
                return a.y>b.y;
            else
                return a.z>b.z;
        }
        else
            return
                a.x>b.x;

    }
};

vector<int> solution(vector<int> t, vector<int> r) {
    vector<pair<int, pair<int, int> > > agr;
    vector<int> answer;
    priority_queue<Abc, vector<Abc>, cmp> pq;
    int size = t.size();
    for(int i=0;i<size;i++)
        agr.push_back(make_pair(t[i], make_pair(r[i], i)));
    sort(agr.begin(), agr.end());

    int agrsize = agr.size();
    int time = 0, tmax = agr[agrsize-1].first;
    while (time<=tmax){
        for(int i=0;i<agrsize;i++){
            if(time==agr[i].first)
                pq.push(Abc(agr[i].second.first, agr[i].second.second, agr[i].first));
        }
        if(pq.empty()){
            time++;
            continue;
        } 
        answer.push_back(pq.top().y);
        pq.pop();
        time++;
    }
    while(!pq.empty()){
        answer.push_back(pq.top().y);
        pq.pop();
    }

    return answer;
}