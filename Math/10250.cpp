#include<iostream>
using namespace std;
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int h,w,n,ans=0;
        cin>>h>>w>>n;
        int mod = n%h;
        int div = 1+n/h;
        if(mod>0) {
            ans+=100*mod;
            ans+=div;
        }
        else {
            ans+=100*h;
            ans+=div-1;
        }
        cout<<ans<<'\n';
    }
    return 0;
}