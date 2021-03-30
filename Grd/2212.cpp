#include<iostream>
#include<algorithm>
using namespace std;
int n,k,a[10001],ans,gap[1000];
bool comp(int x,int y){
    return x>y;
}
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n>>k;
    ans = INT32_MAX;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    for(int i=0;i<n-1;i++) gap[i]=a[i+1]-a[i];
    sort(gap,gap+n-1,comp);
    ans = a[n-1]-a[0];
    for(int i=0;i<k-1;i++) ans-=gap[i];
    cout<<ans<<'\n';
    return 0;
}