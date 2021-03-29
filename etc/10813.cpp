#include<iostream>
using namespace std;
int n,m,d[101];
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;
    for(int k=1;k<=n;k++) d[k]=k;
    for(int k=0;k<m;k++){
        int i,j,ti;
        cin>>i>>j;
        ti = d[i];
        d[i]=d[j];
        d[j]=ti;
    }
    for(int k=1;k<=n;k++) cout<<d[k]<<' ';
    return 0;
}