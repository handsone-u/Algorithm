#include <string>
#include <vector>

using namespace std;
int d[1001][1001];
int dx[3]={1,0,-1}, dy[3]={0,1,-1};
bool ck(int x,int y,int s, int num){
    int tx = x+dx[s], ty = y+dy[s];
    if(tx<0||ty<0||tx>num||ty>num) return false;
    if(d[tx][ty]) return false;
    return true;
}
vector<int> solution(int n) {
    vector<int> answer;
    long long k = n*(n+1)/2;
    int state=0;
    d[1][1]=1;
    int x=1, y=1;
    for(int i=1;i<=k;i++){
        d[x][y]=i;
        if(!ck(x,y,state, n))
            state=(state+1)%3;
        x=x+dx[state];
        y=y+dy[state];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++) answer.push_back(d[i][j]);
    }
    return answer;
}