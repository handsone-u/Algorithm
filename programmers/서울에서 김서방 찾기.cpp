#include <string>
#include <vector>
using namespace std;

string solution(vector<string> seoul) {
    string answer = "김서방은 ";
    int len = seoul.size(),loc=0;
    for(int i=0;i<len;i++)
        if(seoul[i]=="Kim"){
            loc=i;
            break;
        }
    int d = 1000;
    bool z = loc%10 ==0;
    while(d>=1){
        if(loc/d){
            answer+=('0'+loc/d);
            loc = loc%d;
        }
        d/=10;
    }
    if(z)
        answer+="0";
    answer += "에 있다";
    return answer;
}