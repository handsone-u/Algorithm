#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Mystr{
public:
    int from,to,box;
    Mystr(int a,int b,int c):from(a), to(b), box(c) {};
    Mystr(){};
};
bool cmp(Mystr &a,Mystr &b){
    return a.to<b.to;
}
int n,c,m,ans,b[2001];
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n>>c>>m;
    vector<Mystr> v;
    vector<int> town(n+1, c);
    for(int i=0;i<m;i++){
        int from, to, box;
        cin>>from>>to>>box;
        v.push_back(Mystr(from,to,box));
    }
    sort(v.begin(),v.end(),cmp);
    for(auto d :v){
        int min = town[d.from];
        for(int i=d.from+1;i<d.to;i++)
            if(min>town[i]) min=town[i];
        int box = d.box;
        if(box>min) box=min;
        ans+=box;
        for(int i=d.from;i<d.to;i++)
            town[i]-=box;
    }
    cout<<ans<<'\n';
    return 0;
}