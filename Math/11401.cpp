#include <iostream>
using namespace std;
int n,k;
long long dp[4000001][400001];
int func(int a,int b){
    if(a==b||a==0||b==0) return 1;
    if(a==1) return b;
    if(b==1) return a;
    if(dp[a][b]>0) return dp[a][b];
    dp[a][b] = (func(a-1,b)+func(a-1,b-1))%10007;
    return dp[a][b];
}
int main()
{
    ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin>>n>>k;
    cout << func(n,k) << endl;
    return 0;
}