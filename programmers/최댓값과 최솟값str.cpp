#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

vector<string> tok(string str, char del){
    vector<string> rtn;
    stringstream ss(str);
    string tmp;
    while(getline(ss, tmp, del))
        rtn.push_back(tmp);
    return rtn;
}

string solution(string s) {
    string answer = "";
    int n=0;
    vector<string> tmp = tok(s, ' ');
    vector<int> num;
    for(auto it : tmp)
        num.push_back(stoi(it));
    n = num.size();
    sort(num.begin(), num.end());
    string mini = to_string(num[0]), maxi = to_string(num[n-1]);
    answer+=mini;
    answer+=" ";
    answer+=maxi;
    return answer;
}