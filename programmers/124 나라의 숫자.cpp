#include <string>
#include <vector>
using namespace std;

string solution(int n) {
    string answer = "";
    char num[3]={'4','1','2'};
    while(n>0){
        int mod = n%3;
        answer = num[mod] + answer;
        if(mod==0){
            n/=3;
            n--;
        }
        else
            n/=3;
    }
    return answer;
}