#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0, n = priorities.size();
    vector<int> ans;
    queue<int> q;
    for(int i=0;i<n;i++) q.push(i);
    while(!q.empty()){
        int idx = q.front(); q.pop();
        if(priorities[idx]>=*max_element(priorities.begin(), priorities.end())){
            ans.push_back(idx);
            priorities[idx]=-1;
        }
        else{
            q.push(idx);
        }
    }
    for(int i=0;i<n;i++)
        if(ans[i]==location) answer=i+1;
    return answer;
}