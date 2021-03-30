#include<iostream>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t,v,e,ans;
    cin>>t;
    while(t--){
        ans = 0;
        cin>>v>>e;
        ans = e-v+2;
        cout<<ans<<'\n';
    }
    return 0;
}