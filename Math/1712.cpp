#include<iostream>
using namespace std;
long long ans,a,b,c;
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>a>>b>>c;
    int gap = b-c;
    if(gap>=0){
        cout<<-1<<'\n';
        return 0;
    }
    gap = -1*gap;
    ans = a/gap + 1;
    cout<<ans<<'\n';
    return 0;
}