#include<iostream>
#include<queue>
using namespace std;
int r,c,ans,dx[4]={1,0,-1,0},dy[4]={0,1,0,-1},ck[51][51];
char map[51][51];
bool found;
pair<int,int> d;
bool pos(int x,int y){
    if(x<0||y<0||x>=r||y>=c) return false;
    else return true;
}
bool water(int x,int y){
    if(x==d.first&&y==d.second) return true;
    for(int i=0;i<4;i++){
        int tx = x+dx[i], ty = y+dy[i];
        if(!pos(tx,ty)) continue;
        if(ck[tx][ty]==2) return false;
    }
    return true;
}
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    queue<pair<int, int> > q;
    queue<pair<int, int> > w;
    cin>>r>>c;
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++) {
            char c;
            cin>>c;
            map[i][j]=c;
            if(c=='S') q.push(make_pair(i,j)),ck[i][j]=1;
            else if(c=='D') d=make_pair(i,j);
            else if(c=='*') w.push(make_pair(i,j)),ck[i][j]=2;
        }
    while(!q.empty()){
        int qsize = q.size();
        for(int i=0;i<qsize;i++){
            pair<int,int> cur = q.front();
            q.pop();
            if(cur.first==d.first&&cur.second==d.second){
                found=true;
                break;
            }
            for(int j=0;j<4;j++){
                int tx=cur.first+dx[j], ty=cur.second+dy[j];
                if(!pos(tx,ty)) continue;
                if(ck[tx][ty]) continue;
                if(map[tx][ty]=='X') continue;
                if(!water(tx,ty)) continue;
                q.push(make_pair(tx,ty));
                ck[tx][ty]=1;
            }
        }
        if(found) break;
        int wsize = w.size();
        for(int i=0;i<wsize;i++){
            pair<int,int> cur = w.front();
            w.pop();
            for(int j=0;j<4;j++){
                int tx=cur.first+dx[j], ty=cur.second+dy[j];
                if(!pos(tx,ty)) continue;
                if(ck[tx][ty]==2) continue;
                if(map[tx][ty]=='X'||map[tx][ty]=='D') continue;
                w.push(make_pair(tx,ty));
                ck[tx][ty]=2;
            }
        }
        ans++;
    }
    if(found) cout<<ans<<'\n';
    else cout<<"KAKTUS\n";
    return 0;
}