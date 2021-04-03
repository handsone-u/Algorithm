#include<iostream>
#include<queue>
#include<cmath>
using namespace std;
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,x,y;
        pair<int, int> p[102];
        queue<int> q;
        bool ck[101] = {false, };
        bool ans = false;
        cin>>n;
        cin>>x>>y;
        p[0] = make_pair(x,y);
        for(int k=1;k<=n;k++){
            cin>>x>>y;
            p[k] = make_pair(x,y);
        }
        cin>>x>>y;
        p[n+1] = make_pair(x,y);
        q.push(0); ck[0]=true;
        while(!q.empty()){
            pair<int,int> point = p[q.front()]; q.pop();
            int dist = abs(p[n+1].first-point.first)+abs(p[n+1].second-point.second);
            if(dist<=1000){
                ans=true;
                break;
            }
            for(int k=1;k<=n;k++){
                if(ck[k]) continue;
                int tdist = abs(p[k].first-point.first)+abs(p[k].second-point.second);
                if(tdist>1000) continue;
                q.push(k); ck[k]=true;
            }
        }
        ans ? cout<<"happy\n" : cout<<"sad\n";
    }
    return 0;
}