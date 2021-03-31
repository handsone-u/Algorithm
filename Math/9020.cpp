#include<iostream>
using namespace std;
bool ck[10001];
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,t;
    cin>>t;
    for(int i=2;i<=10000;i++){
        if(ck[i]) continue;
        for(int j=2;j*i<=10000;j++)
            ck[j*i]=true;
    }
    while(t--){
        cin>>n;
        int k,j;
        for(int i=2;i<=n/2;i++){
            int x = n - i;
            if(!ck[x]&&!ck[i]) k=i,j=x;
        }
        cout<<k<<' '<<j<<'\n';
    }   
    return 0;
}