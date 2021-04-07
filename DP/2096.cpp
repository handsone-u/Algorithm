#include<iostream>
#include<algorithm>
using namespace std;
int n,dpmax[2][3],dpmin[2][3];
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(int i=0;i<3;i++) {
        cin>>dpmax[0][i];
        dpmin[0][i]=dpmax[0][i];
    }
    for(int i=1;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        dpmax[1][0]= max(dpmax[0][0],dpmax[0][1])+a;
        dpmin[1][0]= min(dpmin[0][0],dpmin[0][1])+a;
        dpmax[1][1]= max({dpmax[0][0],dpmax[0][1],dpmax[0][2]})+b;
        dpmin[1][1]= min({dpmin[0][0],dpmin[0][1],dpmin[0][2]})+b;
        dpmax[1][2]= max(dpmax[0][1],dpmax[0][2])+c;
        dpmin[1][2]= min(dpmin[0][1],dpmin[0][2])+c;
        for(int j=0;j<3;j++){
            dpmax[0][j]=dpmax[1][j];
            dpmin[0][j]=dpmin[1][j];
        }
    }
    int mini = min({dpmin[0][0],dpmin[0][1],dpmin[0][2]});
    int maxi = max({dpmax[0][0],dpmax[0][1],dpmax[0][2]});
    cout<<maxi<<' '<<mini<<'\n';
    return 0;
}