#include<iostream>
#include<cmath>
#define INF 1e9
#define MIN(a, b)(a < b ? a : b)
using namespace std;
int n,x[16],y[16];
double dist[16][16], dp[16][1<<16];

double tsp(int node, int cur){
    if(cur==(1<<n)-1){
        if(dist[node][0]==0) return INF;
        else return dist[node][0];
    }
    if(dp[node][cur]) return dp[node][cur];
    dp[node][cur] = INF;

    for(int i=0;i<n;i++){
        if(i==node) continue;
        int tmp = (1<<i);
        if((tmp&cur)!=0) continue;
        dp[node][cur] = MIN(dp[node][cur], dist[node][i]+tsp(i, cur|tmp));
    }

    return dp[node][cur];
}

int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>x[i]>>y[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) continue;
            if(dist[i][j]) continue;
            dist[i][j]=dist[j][i]=sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2));
        }
    }
    cout.setf(ios::fixed);
    cout.precision(6);
    cout<<tsp(0,1);

    return 0;
}