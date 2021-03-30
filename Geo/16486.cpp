#include<iostream>
#define PI 3.141592
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int d1,d2;
    double ans = 0;
    cin>>d1>>d2;
    ans += 2*d1+2*d2*PI;
    cout<<fixed;
    cout.precision(6);
    cout<<ans<<'\n';
    return 0;
}