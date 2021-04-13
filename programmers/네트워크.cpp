#include <string>
#include <vector>

using namespace std;
void dfs(int node, vector<vector<int> > &com, vector<bool> &c){
    c[node] = true;
    int len = com.size();
    for(int i=0;i<len;i++){
        if(com[node][i]==0) continue;
        if(c[i]) continue;
        dfs(i, com, c);
    }
}
int solution(int n, vector<vector<int> > computers) {
    int answer = 0;
    vector<bool> ck(n, false);
    for(int i=0;i<n;i++){
        if(ck[i]) continue;
        dfs(i, computers, ck);
        answer++;
    }
    return answer;
}