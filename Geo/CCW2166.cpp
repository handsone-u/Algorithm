#include<iostream>
using namespace std;
long long n,x[100001],y[100001];

long long ccw(long x1,long y1,long x2, long y2,long x3,long y3){
    return (x1*y2+x2*y3+x3*y1)-(x2*y1+x3*y2+x1*y3);
}

int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    double ans = 0;
    for(int i=0;i<n;i++) cin>>x[i]>>y[i];
    for(int i=1;i<n-1;i++)
        ans+=ccw(x[0],y[0],x[i],y[i],x[i+1],y[i+1]);
    if(ans<0) ans = -1*ans;
    cout<<fixed;
    cout.precision(1);
    cout<<ans/2;
    return 0;
}