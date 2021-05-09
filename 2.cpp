#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};
bool found = false;

bool ck(int x,int y){
    if(x<0||y<0||x>=5||y>=5) return false;
    else return true;   
}

void bfs(int x, int y, int d, vector<string> &now){
    queue<pair<int,int> > q;
    q.push(make_pair(x, y));
    int level = 0;
    while (!q.empty()) {
        int qsize = q.size();
        
        for(int i=0;i<qsize;i++){
            int nx = q.front().first;
            int ny = q.front().second;
            q.pop();
            if(now[nx][ny]=='X') continue;
            else if(now[nx][ny]=='P'){
                if(!(nx==x&&ny==y)){
                    found=true;
                    return;
                }
            }
            for(int k=0;k<4;k++){
                int tx = nx+dx[k], ty = ny+dy[k];
                if(!ck(tx ,ty)) continue;
                if(tx==x&&ty==y) continue;
                q.push(make_pair(tx,ty));
            }
        }
        level++;
        if(level>2) return;
    }
    
}

vector<int> solution(vector<vector<string> > places) {
    vector<int> answer;
    for(int i=0;i<5;i++){
        bool ck = true;

        vector<string> tmp = places[i];

        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                if(tmp[i][j]!='P') continue;
                found = false;
                bfs(i,j,0,tmp);
                if(found){
                    ck=false;
                    i=j=5;
                    break;
                }
            }
        }
        if(ck) answer.push_back(1);
        else answer.push_back(0);
        cout<<i<<' '<<answer[i]<<endl;
    }
    return answer;
}