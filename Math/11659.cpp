#include<iostream>
using namespace std;
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int i,j,t,n,m,a[100001];
    cin>>n>>m;
    a[0]=0;
    for(int i=1;i<=n;i++){
        cin>>t;
        a[i]=a[i-1]+t;
    }
    while(m--)cin>>i>>j, cout<<a[j]-a[i-1]<<'\n';
    return 0;
}