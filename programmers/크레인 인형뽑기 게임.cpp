#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int> > board, vector<int> moves) {
    int box = board.size();
    int msize = moves.size();
    int answer = 0;
    stack<int> st;
    for(int i=0;i<msize;i++){
        int col = moves[i]-1, dol=0;
        for(int k=0;k<box;k++){
            dol = board[k][col];
            if(dol==0) continue;
            board[k][col]=0;
            break;
        }
        if(dol==0) continue;
        if(st.empty()){
            st.push(dol);
            continue;
        }
        int what = st.top();
        if(what==dol){
            answer+=2;
            st.pop();
        }
        else{
            st.push(dol);
        }
    }
    return answer;
}