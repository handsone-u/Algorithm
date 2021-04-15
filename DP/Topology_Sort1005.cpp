#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int t,n,k,w;
int d[1001],pion[1001];
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>t;
    while(t--){
        int b[1001]={0,};
        vector<int> node[1001];
        queue<int> q;
        cin>>n>>k;
        for(int i=1;i<=n;i++) cin>>b[i];
        fill_n(d,n+1,0);
        fill_n(pion,n+1,0);
        for(int i=0;i<k;i++){
            int x,y;
            cin>>x>>y;
            node[x].push_back(y);
            pion[y]++;
        }
        cin>>w;
        for(int i=1;i<=n;i++) if(pion[i]==0) {
            d[i]=b[i];
            q.push(i);
        }
        while(!q.empty()){
            int x = q.front();q.pop();
            int vsize = node[x].size();
            for(int i=0;i<vsize;i++){
                int tnode = node[x][i];
                if(pion[tnode]) pion[tnode]--;
                if(pion[tnode]==0) q.push(tnode);
                int tmp = b[tnode]+d[x];
                if(d[tnode]<tmp)
                    d[tnode]=tmp;
            }
        }
        cout<<d[w]<<'\n';
    }
    return 0;
}