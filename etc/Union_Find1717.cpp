#include<iostream>
using namespace std;
int n,m,p[1000001];
int find(int x){
    if(x==p[x]) return x;
    return p[x]=find(p[x]);
}
void uni(int x,int y){
    int xp = find(x);
    int yp = find(y);
    if(xp==yp) return;
    p[yp]=x;
}
bool parent(int x,int y){
    int xp=find(x);
    int yp=find(y);
    if(xp==yp) return true;
    else return false;
}
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;
    for(int i=0;i<=n;i++) p[i]=i;
    for(int i=0;i<m;i++){
        int op,a,b;
        cin>>op>>a>>b;
        if(a>b){
            int tmp=a;
            a=b;
            b=tmp;
        }
        if(op==0){
            uni(a,b);
            continue;
        }
        parent(a,b) ? cout<<"YES\n" : cout<<"NO\n";
    }
    return 0;
}