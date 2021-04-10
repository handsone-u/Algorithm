#include <string>
#include <vector>
#include <algorithm>
using namespace std;
char cap[26], mi[26];
string solution(string s) {
    string answer = "";
    int len = s.size();
    for(int i=0;i<len;i++){
        char t = s[i];
        if(t<='Z'&&t>='A') cap[t-'A']++;
        else mi[t-'a']++;
    }
    for(int i=25;i>=0;i--){
        if(mi[i])
            for(int j=0;j<mi[i];j++) answer+=char('a'+i);
    }
    for(int i=25;i>=0;i--){
        if(cap[i])
            for(int j=0;j<cap[i];j++) answer+=char('A'+i);
    }
    return answer;
}