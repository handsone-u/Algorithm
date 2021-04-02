#include<iostream>
using namespace std;
int ans,x;
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>x;
    while(x>0){
        ans += x&1;
        x/=2;
    }
    cout<<ans<<'\n';
    return 0;
}