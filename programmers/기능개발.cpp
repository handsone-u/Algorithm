#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<pair<int, int> > d;
    int n = progresses.size();
    for(int i=0;i<n;i++)
        d.push_back(make_pair(progresses[i], i));
    while (!d.empty()){
        int dsize = d.size();
        for(int i=0;i<dsize;i++){
            if(d[i].first>=100) continue;
            d[i].first+=speeds[d[i].second];
        }
        if(d[0].first<100) continue;
        int cnt = 0;
        for(int i=0;i<dsize;i++){
            if(d[i].first>=100) cnt++;
            else break;
        }
        for(int i=0;i<cnt;i++)
            d.erase(d.begin());
        answer.push_back(cnt);
    }
    return answer;
}