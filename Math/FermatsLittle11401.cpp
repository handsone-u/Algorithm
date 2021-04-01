
#include <iostream>
using namespace std;
int n,k;
long long mpow(long long x,long long y){
    if(y==1) return x;
    if(y%2==0){
        long long tmp = mpow(x,y/2);
        return (tmp*tmp)%1000000007;
    }
    else
        return (x*mpow(x,y-1))%1000000007;
}
int main()
{
    ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin>>n>>k;
    if(n==k||k==0){
        cout<<1<<'\n';
        return 0;
    }
    else if(k==1){
        cout<<n<<'\n';
        return 0;
    }
    long long kp, np, nkp, ans, a;
    kp = np = nkp = 1;
    for(int i=1;i<=n;i++){
        np = (np*i)%1000000007;
        if(i==k) kp = np;
        if(i==n-k) nkp = np;
    }
    a = (kp*nkp)%1000000007;
    a = mpow(a,1000000005)%1000000007;
    ans = (np*a)%1000000007;
    cout<<ans<<'\n';
    return 0;
}