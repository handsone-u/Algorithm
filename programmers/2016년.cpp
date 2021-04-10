#include <string>
#include <vector>
using namespace std;
int month[13] ={0,31,29,31,30,31,30,31,31,30,31,30,31};
string date[7] ={"THU","FRI","SAT","SUN","MON","TUE","WED"};
string solution(int a, int b) {
    string answer = "";
    int cnt = 0;
    for(int i=1;i<a;i++)
        cnt+=month[i];
    cnt+=b;
    cnt = cnt%7;
    answer = date[cnt];
    return answer;
}