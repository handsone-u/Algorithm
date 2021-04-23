#include<iostream>
#include<queue>
#include<cmath>
using namespace std;
int n;
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    priority_queue<pair<int, int> > pq;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        if(x==0&&pq.empty()) cout<<0<<'\n';
        else if(x==0){
            cout<<-pq.top().second<<'\n';
            pq.pop();
        }
        else{
            int absx = -abs(x);
            pq.push(make_pair(absx, -x));
        }
    }

    return 0;
}