#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <set>
using namespace std;


string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    int csize = cmd.size(), current = n;
    vector<int> row(n);
    stack<pair<int, int> > stck;

    for(int i=0;i<n;i++)
        row[i]=i;

    for(int i=0;i<csize;i++){
        char cmdChar = cmd[i][0];
        if(cmdChar=='U'||cmdChar=='D'){
            int tmpsize = cmd[i].size();
            int num = 0;
            for(int j=2;j<tmpsize;j++)
                num = num*10 + (cmd[i][j]-'0');
            int cnt = 0;
            if(cmdChar=='U'){
                while(cnt!=num){
                    k--;
                    if(row[k]==0) continue;
                    else cnt++;
                }
            }
            else{
                while(cnt!=num){
                    k++;
                    if(row[k]==0) continue;
                    else cnt++;
                }
            }
        }
        else if(cmdChar=='C'){

            stck.push(make_pair(k, row[k]));
            row[k]=0;

            int cnt=0;
            if(k+1==current){
                int num=1;
                while(cnt!=num){
                    k--;
                    if(row[k]==0) continue;
                    else cnt++;
                }
            }
            else{
                int num=1;
                while(cnt!=num){
                    k++;
                    if(row[k]==0) continue;
                    else cnt++;
                }
            }
            current--;
        }
        else{
            int drow = stck.top().first, dval = stck.top().second;
            stck.pop();

            row[drow]=dval;
            current++;
        }
    }
    for(int i=0;i<n;i++){
        if(row[i]==0) answer+='X';
        else answer+='O';
    }

    return answer;
}