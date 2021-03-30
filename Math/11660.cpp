#include<iostream>
using namespace std;
int arr[1025][1025];
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,m,a;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            cin>>a;
            arr[i][j]=a+arr[i][j-1];
        }
    while(m--){
        int x1,x2,y1,y2;
        a=0;
        cin>>x1>>y1>>x2>>y2;
        for(int x=x1;x<=x2;x++)
            a+=arr[x][y2]-arr[x][y1-1];
        cout<<a<<'\n';
    }
    return 0;
}