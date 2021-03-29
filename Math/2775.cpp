#include<iostream>
using namespace std;
int t,n,k;
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>t;
    while(t--){
        cin>>k>>n;
        int d[15][15];
        for(int i=1;i<=n;i++) d[0][i]=i;
        for(int i=1;i<=k;i++)
            for(int j=1;j<=n;j++){
                int tmp = 0;
                for(int x=1;x<=j;x++) tmp+=d[i-1][x];
                d[i][j]=tmp;
            }
        cout<<d[k][n]<<'\n';
    }
    return 0;
}