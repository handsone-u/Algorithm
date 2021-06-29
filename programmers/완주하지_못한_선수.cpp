#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> mp;
    int len = participant.size();
    for(int i=0;i<len;i++){
        string tmp = participant[i];
        if(mp.find(tmp)==mp.end())
            mp.insert({tmp, 1});
        else
            mp[tmp]++;
    }
    len--;
    for(int i=0;i<len;i++){
        string tmp = completion[i];
        if(mp.find(tmp)->second==1) mp.erase(tmp);
        else mp[tmp]--;
    }
    answer=mp.begin()->first;
    return answer;
}