#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
int dp[1001][1001];
int solution(vector<vector<int> > board)
{
    int answer = 0;
    int n = board.size();
    int m = board[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]==0) continue;
            else dp[i][j]=1;
            if(i==0||j==0) continue;
            int lhs = dp[i][j-1];
            int cros = dp[i-1][j-1];
            int rhs = dp[i-1][j];
            int mini = min({lhs,rhs,cros});
            if(mini==0) continue;
            else dp[i][j]=mini+1;
            if(dp[i][j]>answer) answer=dp[i][j];
        }
    }
    if(answer==0)
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(dp[i][j]==1){
                    answer=1;
                    break;
                }
    return answer*answer;
}