#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

class Abc {
public:
    int x,y;

    Abc(int xt,int yt) {
        x=xt;
        y=yt;
    }
};

struct cmp {
    bool operator()(Abc a, Abc b) {
        if(a.x==b.x)
            return a.y>b.y;
        else
            return a.x>b.x;
    }
};

int main() {
    priority_queue<Abc, vector<Abc>, cmp> pq;
    pq.push(Abc(3,0));
    pq.push(Abc(2,0));
    pq.push(Abc(4,0));
    pq.push(Abc(4,1));
    pq.push(Abc(2,1));
    while(!pq.empty()){
        cout<<pq.top().x<<' '<<pq.top().y<<endl;
        pq.pop();
    }
}
