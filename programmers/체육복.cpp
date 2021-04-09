#include <string>
#include <vector>

using namespace std;
int s[32];
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    for(auto it : reserve) s[it]++;
    for(auto it : lost) s[it]--;
    for(int i=1;i<=n;i++){
        if(s[i]>=0) continue;
        if(s[i-1]==1) s[i-1]=s[i]=0;
        else if(s[i+1]==1) s[i+1]=s[i]=0;
    }
    for(int i=1;i<=n;i++)
        if(s[i]>=0) answer++;
    return answer;
}