#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int len = s.size();
    int mid = len/2;
    if(len%2==1){
        answer+=s[mid];
    }
    else{
        answer+=s[mid-1];
        answer+=s[mid];
    }
    return answer;
}