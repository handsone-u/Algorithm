#include <string>
#include <vector>
#include <algorithm>
int global;
using namespace std;
bool cmp(string a, string b){
    if(a[global]==b[global])
        return a<b;
    return a[global]<b[global];
}
vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    global=n;
    sort(strings.begin(), strings.end(), cmp);
    answer=strings;
    return answer;
}