#include<iostream>
using namespace std;
int n,b[1001],dp[1001],ans;
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++) cin>>b[i];
    dp[0]=1;
    for(int i=1;i<n;i++){
        dp[i]=1;
        for(int j=0;j<i;j++){
            if(b[j]<b[i]){
                int tmp = dp[j]+1;
                if(dp[i]<tmp) dp[i]=tmp;
            }
        }
    }
    for(int i=0;i<n;i++) if(ans<dp[i]) ans=dp[i];
    cout<<ans<<'\n';
    return 0;
}