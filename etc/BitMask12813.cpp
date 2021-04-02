#include<iostream>
using namespace std;
char a[100001],b[100001],ans[5][100001];
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>a>>b;
    for(int i=0;i<100000;i++){
        if(a[i]==b[i]&&a[i]=='1') ans[0][i]='1';
        else ans[0][i]='0';
        if(a[i]=='1'||b[i]=='1') ans[1][i]='1';
        else ans[1][i]='0';
        if(a[i]==b[i]) ans[2][i]='0';
        else ans[2][i]='1';
        if(a[i]=='1') ans[3][i]='0';
        else ans[3][i]='1';
        if(b[i]=='1') ans[4][i]='0';
        else ans[4][i]='1';
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<100000;j++) cout<<ans[i][j];
        cout<<'\n';
    }
    return 0;
}