#include<iostream>
using namespace std;
int n,m,map[21][21],x,y,k,inst,dx[5]={0,0,0,-1,+1},dy[5]={0,1,-1,0,0},dice[6];
bool pos(int t1,int t2){
    if(t1<0||t2<0||t1>=n||t2>=m) return false;
    return true;
}
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m>>x>>y>>k;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) cin>>map[i][j];
    int top = 1, bot = 6, east=3,north=2,west=4,south=5;
    for(int i=0;i<k;i++){
        cin>>inst;
        if(!pos(x+dx[inst],y+dy[inst])) continue;
        x+=dx[inst], y+=dy[inst];
        int tmp=bot;
        switch (inst){
        case 1: //e
            bot = east;
            east = top;
            top = west;
            west = tmp;
            break;
        case 2: // w
            bot = west;
            west = top;
            top = east;
            east = tmp;
            break;
        case 3: // n
            bot = north;
            north = top;
            top = south;
            south = tmp;
            break;
        default: // s
            bot = south;
            south = top;
            top = north;
            north = tmp;
            break;
        }
        if(map[x][y]==0) map[x][y]=dice[bot];
        else {
            dice[bot]=map[x][y];
            map[x][y]=0;
        }
        cout<<dice[top]<<'\n';
    }
    return 0;
}