#include <string>
#include <vector>
#include <algorithm>
#define INF 20001
using namespace std;

int solution(int n, vector<vector<int> > edge) {
    int answer = 0, done = 0, m = edge.size();
    vector<bool> ck(n+1, false);
    vector<int> d(n+1, INF);
    vector<vector<int> > p(n+1);
    for(int i=0;i<m;i++){
        int f = edge[i][0], b = edge[i][1];
        p[f].push_back(b);
        p[b].push_back(f);
    }
    d[1] = 0;
    ck[1]=true;
    done = 1;
    int next = 1, maxi = 0;
    while(done<=n){
        ck[next]=true;
        int psize = p[next].size();
        done++;
        for(int i=0;i<psize;i++){
            int conn = p[next][i];
            if(ck[conn]) continue;
            d[conn] = min(d[conn], d[next]+1);
            if(d[conn]>maxi) maxi=d[conn];
        }
        int mini = INF;
        for(int i=1;i<=n;i++){
            if(ck[i]) continue;
            if(mini>d[i]){
                next=i;
                mini=d[i];
            }
        }
    }
    return answer;
}