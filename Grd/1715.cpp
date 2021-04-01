#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int ans,n;
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    priority_queue<int, vector<int>, greater<int> > q;
    cin>>n;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        q.push(tmp);
    }
    if(n==1) q.pop();
    while(!q.empty()){
        int f = q.top();
        q.pop();
        int s = q.top();
        q.pop();
        int sum = s+f;
        ans += sum;
        if(q.empty()) break;
        q.push(sum);
    }
    cout<<ans<<'\n';
    return 0;
}