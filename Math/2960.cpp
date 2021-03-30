#include<iostream>
using namespace std;
int n,k,cnt;
bool ck[1001];
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n>>k;
    for(int i=2;i<=n&&cnt!=k;i++){
        if(ck[i])continue;
        for(int j=1;j*i<=n&&cnt!=k;j++){
            if(ck[j*i]) continue;
            ck[j*i]=true;
            cnt++;
            if(cnt==k) cout<<j*i<<'\n';
        }
    }
    return 0;
}