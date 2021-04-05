#include<iostream>
#include<queue>
using namespace std;
int n,m,depth,dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
bool ck[11][11][11][11];
char b[11][11];
class Game{
public:
    int rx,ry,bx,by;
    Game(int a,int b,int c,int d): rx(a), ry(b), bx(c), by(d) {};
};
void move(int &x,int &y,int &cnt, int tx,int ty){
    while(b[x+tx][y+ty]!='#'&&b[x][y]!='O'){
        cnt+=1;
        x+=tx;
        y+=ty;
    }
}
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    queue<Game> q;
    int rx,ry,bx,by;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) {
            cin>>b[i][j];
            if(b[i][j]=='B') bx=i,by=j;
            else if(b[i][j]=='R') rx=i,ry=j;
        }
    Game place(rx,ry,bx,by);
    ck[rx][ry][bx][by]=true;
    q.push(place);
    while(!q.empty()){
        int size = q.size();
        for(int k=0;k<size;k++){
            Game place = q.front(); q.pop();
            rx=place.rx, ry=place.ry, bx=place.bx, by=place.by;
            for(int i=0;i<4;i++){
                int rc=0, bc=0;
                int rtx=rx, rty=ry, btx=bx, bty=by;
                move(rtx,rty,rc,dx[i],dy[i]);
                move(btx,bty,bc,dx[i],dy[i]);
                if(b[btx][bty]=='O') continue;
                if(b[rtx][rty]=='O'){
                    cout<<depth+1<<'\n';
                    return 0;
                }
                if(rtx==btx&&rty==bty){
                    if(rc>bc) rtx-=dx[i], rty-=dy[i];
                    else btx-=dx[i], bty-=dy[i];
                }
                if(ck[rtx][rty][btx][bty]) continue;
                ck[rtx][rty][btx][bty] = true;
                q.push(Game(rtx,rty,btx,bty));
            }
        }
        if(++depth>=10) break;
    }
    cout<<-1<<'\n';
    return 0;
}