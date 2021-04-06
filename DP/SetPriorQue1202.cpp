#include<iostream>
#include<set>
#include<queue>
#include<vector>
#include <map>
#include<algorithm>
#define pp pair<long long ,long long>
using namespace std;
long long n,k,ans;
multiset<long long> bag;
priority_queue<pp, vector<pp> > q;
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int m,v;
        cin>>m>>v;
        q.push( {v,m} );
    }
    for(int i=0;i<k;i++){
        int c;
        cin>>c;
        bag.insert(c);
    }
    while(!q.empty()){
        pp tmp = q.top(); q.pop();
        long long v = tmp.first, m = tmp.second;
        auto it = bag.lower_bound(m);
        if(it==bag.end()) continue;
        ans+=v;
        bag.erase(it);
    }
    cout<<ans<<'\n';
    return 0;
}