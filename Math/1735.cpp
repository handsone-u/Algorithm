#include<iostream>
#include<algorithm>
using namespace std;
int a,b,c,d;
int gcd(int a,int b){
    return b ? gcd(b, a%b) : a;
}
int main(){
    // iostream : c++ speed up
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>a>>b>>c>>d; // a/b, c/d
    int g = gcd(b,d);
    int down = (d*b)/g;
    int up = (a*d)/g + (c*b)/g;
    int com = gcd(up,down);
    cout<<up/com<<' '<<down/com;
    return 0;
}