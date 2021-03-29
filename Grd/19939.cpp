#include<iostream>
using namespace std;
int n,k,gap,t;
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n>>k;
    t = (k*(k+1))/2;
    if(n<t){
        cout<<-1<<'\n';
        return 0;
    }
    gap = k-1;
    n-=t;
    if(n%k==0) cout<<gap<<'\n';
    else cout<<gap+1<<'\n';
    return 0;
}