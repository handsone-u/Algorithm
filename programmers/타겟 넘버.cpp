#include <string>
#include <vector>

using namespace std;
int n,t,ans;
void dfs(int sum, int x,vector<int> &tmp){
    if(x==n){
        if(sum==t) ans++;
        return;
    }
    dfs(sum-tmp[x],x+1, tmp);
    dfs(sum+tmp[x],x+1, tmp);
}

int solution(vector<int> numbers, int target) {
    ans = 0, n = numbers.size();
    t=target;
    dfs(0,0,numbers);
    return ans;
}