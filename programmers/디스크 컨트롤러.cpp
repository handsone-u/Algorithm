#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool cmp(vector<int> &a, vector<int> &b){
    if(a[1]==b[1]) return a[0]<b[0];
    return a[1]<b[1];
}
int solution(vector<vector<int> > jobs) {
    int answer = 0, n = jobs.size();
    sort(jobs.begin(), jobs.end(), cmp);
    int curtime = 0, time = 0;
    while(!jobs.empty()){
        int jsize= jobs.size();
        bool ck = false;
        for(int i=0;i<jsize;i++){
            if(jobs[i][0]>curtime) continue;
            curtime += jobs[i][1];
            time += curtime-jobs[i][0];
            jobs.erase(jobs.begin()+i);
            ck=true;
            break;
        }
        if(ck) continue;
        curtime++;
    }
    answer=time/n;
    return answer;
}