#include<iostream>
#include<algorithm>
#define INF 1e9
using namespace std;
int map[17][17], dp[17][1<<17], ans, n;

int tsp(int node, int cur){
    if(cur==(1<<n)-1){
        if(map[node][0]==0) return INF;
        else return map[node][0];
    }

    if(dp[node][cur]) return dp[node][cur];
    dp[node][cur] = INF;

    for(int i=0;i<n;i++){
        if(map[node][i]==0) continue;
        int tmp = (1<<i);
        if((tmp&cur)!=0) continue;
        dp[node][cur] = min(dp[node][cur], map[node][i]+tsp(i, cur+tmp));
    }

    return dp[node][cur];
}

int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n;

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>map[i][j];

    cout<<tsp(0,1);
    return 0;
}