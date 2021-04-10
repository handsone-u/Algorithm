#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(int n) {
    stack<int> tri;
    int answer = 0;
    while(n>=3){
        int cnt = n%3;
        tri.push(cnt);
        n/=3;
    }
    tri.push(n);
    int pow = 1;
    while(!tri.empty()){
        answer+=tri.top()*pow; tri.pop();
        pow*=3;
    }
    return answer;
}