#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int answer = 51;
bool ck=false;
bool diff(string a, string b){
    int len = a.size(), cnt = 0;;
    for(int i=0;i<len;i++)
        if(a[i]!=b[i]) cnt++;
    if(cnt==1) return true;
    else return false;
}
void dfs(int cnt, string now, string t, vector<string> &w, vector<bool> &u){
    if(now==t){
        ck = true;
        if(answer>cnt) answer=cnt;
        return ;
    }
    int len = w.size();
    for(int i=0;i<len;i++){
        if(u[i]) continue;
        if(!diff(now, w[i])) continue;
        u[i]=true;
        dfs(cnt+1, w[i], t, w, u);
        u[i]=false;
    }
}
int solution(string begin, string target, vector<string> words) {
    if(words.end()==find(words.begin(), words.end(), target))
        return 0;
    int n = words.size();
    vector<bool> used(n, false);
    dfs(0, begin, target, words, used);
    if(ck)
        return answer;
    else
        return 0;
}