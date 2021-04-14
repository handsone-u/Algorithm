#include<iostream>
#include<algorithm>
using namespace std;
int n,dp[2001],a[2001];
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        dp[i]=1;
    }
    for(int i=1;i<n;i++)
        for(int j=0;j<i;j++)
            if(a[j]>a[i])
                dp[i]=max(dp[i], dp[j]+1);
    int mx = 0;
    for(int i=0;i<n;i++)
        mx = max(mx, dp[i]);
    cout<<n-mx;
    return 0;
}