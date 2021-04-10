#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    string odd ="수", even ="수박";
    int num = n/2;
    for(int i=0;i<num;i++)
        answer+=even;
    if(n%2) answer+=odd;
    return answer;
}