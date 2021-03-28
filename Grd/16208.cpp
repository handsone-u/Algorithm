#include <iostream>
using namespace std;
int n,a[500001];
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long ans = 0, sum = 0;
    cin>>n;
    int m,x=0,y=n-1,cnt=0;
    for(int i=0;i<n;i++) cin>>a[i],sum+=a[i];
    while(x<y&&cnt<n){
        if(a[x]>a[y]){
            sum-=a[y];
            m=a[y--];
        }
        else{
            sum-=a[x];
            m=a[x++];
        }
        ans+=sum*m;
        n++;
    }  
    cout<<ans<<'\n';
    return 0;
}