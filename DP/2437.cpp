#include<iostream>
#include<algorithm>
using namespace std;
int n,a[1000001],sum[1000001];
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    if(a[0]>1){
        cout<<1<<'\n';
        return 0;
    }
    sum[0]=a[0];
    for(int i=1;i<n;i++) {
        int gap = a[i] - sum[i-1];
        if(gap<=1){
            sum[i]=sum[i-1]+a[i];
            continue;
        }
        if(gap>1){
            cout<<sum[i-1]+1<<'\n';
            return 0;
        }
    }
    cout<<sum[n-1]+1<<'\n';
    return 0;
}