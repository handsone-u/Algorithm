#include<iostream>
#include<queue>
using namespace std;
int n,m,h,b[101][101][101],ans,tot,done;
int dx[6]={1,0,-1,0,0,0}, dy[6]={0,1,0,-1,0,0}, dz[6]={0,0,0,0,1,-1};
class Tom{
public:
    int x,y,z;
    Tom(int a,int b,int c){
        x=a,y=b,z=c;
    }
};
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>m>>n>>h;
    queue<Tom> q;
    tot = m*n*h;
    for(int i=0;i<h;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<m;k++) {
                int t;
                cin>>t;
                b[j][k][i]=t;
                if(t==1)
                    q.push(Tom(j,k,i)),done++;
                else if(t==-1) tot--;
            }
    while(!q.empty()){
        int qsize = q.size();
        for(int i=0;i<qsize;i++){
            Tom tmp = q.front();
            q.pop();
            for(int j=0;j<6;j++){
                int tx = dx[j]+tmp.x, ty = dy[j]+tmp.y, tz = dz[j]+tmp.z;
                if(tx<0||ty<0||tz<0||tx>=n||ty>=m||tz>=h) continue;
                if(b[tx][ty][tz]!=0) continue;
                b[tx][ty][tz]=1;
                q.push(Tom(tx,ty,tz));
                done++;
            }
        }
        ans++;
    }
    if(done==tot) cout<<ans-1<<'\n';
    else cout<<-1<<'\n';
    return 0;
}