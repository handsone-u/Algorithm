#include<iostream>
#include<algorithm>
using namespace std;
int n,m,l,cola,cider;
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m>>l>>cola>>cider;
    int a,b;
    a = min({n,m,l});
    b = min(cola,cider);
    cout<<a+b-50<<'\n';
    return 0;
}