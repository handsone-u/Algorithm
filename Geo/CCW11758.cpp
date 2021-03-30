#include<iostream>
// https://degurii.tistory.com/47
using namespace std;
pair<int,int> p[3];

int ccw(pair<int,int> a,pair<int,int> b,pair<int,int> c){
    int v1 = a.first*b.second + b.first*c.second + c.first*a.second;
    v1 -= b.first*a.second + c.first*b.second + a.first*c.second;
    return v1;
}

int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for(int i=0;i<3;i++){
        int a,b;
        cin>>p[i].first>>p[i].second;
    }
    int k = ccw(p[0],p[1],p[2]);
    if(k>1) cout<<1;
    else if(k==0) cout<<0;
    else cout<<-1;
    return 0;
}