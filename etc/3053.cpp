#include<iostream>
#include<cmath>
using namespace std;
int r;
const double PI = M_PI;
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>r;
    cout<<fixed;
    cout.precision(6);
    cout<<r*r*PI<<'\n';
    cout<<double(2*r*r)<<'\n';
    return 0;
}