#include<iostream>
using namespace std;
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t,n,ans;
    cin>>t;
    while(t--){
        int a[1001];
        bool c[1001]={0,};
        ans = 0;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++){
            if(c[i]) continue;
            ans++;
            if(a[i]==i){
                c[i]=true;
                continue;
            }
            int tmp = i,tmp2 = a[i];
            while(tmp2!=i){
                c[tmp2]=true;
                tmp2=a[tmp2];
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}