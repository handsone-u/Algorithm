#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(string a,string b){
    return a+b>b+a;
}
string solution(vector<int> numbers) {
    string answer = "";
    int n = numbers.size();
    vector<string> str;
    for(int i=0;i<n;i++)
        str.push_back(to_string(numbers[i]));
    sort(str.begin(), str.end(), cmp);

    for(int i=0;i<n;i++)
        answer+=str[i];
    if(str[0]=="0")
        answer = "0";
    return answer;
}