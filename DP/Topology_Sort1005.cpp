#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int t,n,k,w;
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>t;
    while(t--){
        int b[1001]={0,},d[1001]={0,};
        bool pion[1001]={0,};
        vector<int> node[1001];
        queue<int> q;
        cin>>n>>k;
        for(int i=1;i<=n;i++) cin>>b[i];
        for(int i=0;i<k;i++){
            int x,y;
            cin>>x>>y;
            node[x].push_back(y);
            pion[y]=true;
        }
        cin>>w;
        for(int i=1;i<=n;i++){
            if(pion[i]) continue;
            q.push(i);
            d[i]=b[i];
        }
        while(!q.empty()){
            int x = q.front();
            int vsize = node[x].size();
            q.pop();
            for(int i=0;i<vsize;i++){
                int tnode = node[x][i];
                int tmp = b[tnode]+d[x];
                if(d[tnode]<tmp) {
                    d[tnode]=tmp;
                    q.push(tnode);
                }
            }
        }
        cout<<d[w]<<'\n';
    }
    return 0;
}