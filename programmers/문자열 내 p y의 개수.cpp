#include <string>
using namespace std;

bool solution(string s){
    bool answer = true;
    int p=0, y=0, len=s.size();
    for(int i=0;i<len;i++){
        char c = s[i];
        if(c=='p'||c=='P') p++;
        else if(c=='y'||c=='Y') y++;
    }
    if(p == y) answer=true;
    else answer=false;
    return answer;
}