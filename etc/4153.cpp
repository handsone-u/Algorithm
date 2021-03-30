#include<iostream>
#include<algorithm>
#define r "right\n"
#define w "wrong\n"
using namespace std;
int a[3];
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while(true){
        cin>>a[0]>>a[1]>>a[2];
        if(a[0]==a[1]&&a[1]==a[2]){
            if(a[0]==0) break;
            cout<<w;
            continue;
        }
        sort(a,a+3);
        if(a[0]*a[0]+a[1]*a[1]==a[2]*a[2]) cout<<r;
        else cout<<w;
    }
    return 0;
}