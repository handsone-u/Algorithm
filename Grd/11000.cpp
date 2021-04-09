#include<iostream>
#include<queue>
#include<algorithm>
#define pp pair<int, int>
using namespace std;
int n;
bool cmp(pp a, pp b){
    if (a.second==b.second)
        return a.first<b.first;
    return a.second<b.second;
}
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    priority_queue<int, vector<int>, greater<int> > q;
    cin>>n;
    pp c[200001];
    for(int i=0;i<n;i++){
        int s,t; cin>>s>>t;
        c[i].first=s, c[i].second=t;
    }
    sort(c,c+n);
    q.push(c[0].second);
    for(int i=1;i<n;i++){
        int s=c[i].first, e=c[i].second;
        if(q.top()>s)
            q.push(e);
        else{
            q.pop();
            q.push(e);
        }
    }
    cout<<q.size()<<'\n';
    return 0;
}