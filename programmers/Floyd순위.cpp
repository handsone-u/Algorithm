#include <string>
#include <vector>
using namespace std;
bool ck[101][101];
int win[101], lose[101];
int solution(int n, vector<vector<int>> results) {
    int answer = 0, m = results.size();
    vector<int> node[101];
    for(int i=0;i<m;i++){
        int w=results[i][0], l=results[i][1];
        node[w].push_back(l);
        ck[w][l]=true;
        win[w]++; lose[l]++;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(ck[i][j]) continue;
                if(ck[i][k]&&ck[k][j]){
                    ck[i][j]=true;
                    win[i]++; lose[j]++;
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
        if(win[i]+lose[i]==n-1) answer++;

    return answer;
}