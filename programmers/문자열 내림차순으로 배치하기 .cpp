#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(char a, char b){
    return a>b;
}
string solution(string s) {
    string answer = "";
    vector<char> c;
    int len = s.size();
    for(int i=0;i<len;i++)
        c.push_back(s[i]);
    sort(c.begin(), c.end(), cmp);
    for(int i=0;i<len;i++)
        answer+=c[i];
    return answer;
}