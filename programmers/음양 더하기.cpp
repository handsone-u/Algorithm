#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0, n = absolutes.size();
    for(int i=0;i<n;i++){
        if(signs[i]==false) answer-=absolutes[i];
        else answer+=absolutes[i];
    }
    return answer;
}