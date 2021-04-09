#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    int so = clothes.size();
    map<string, int> mp;
    for(int i=0;i<so;i++){
        string kind = clothes[i][1];
        if(mp.find(kind)!=mp.end()) mp[kind]++;
        else mp.insert({kind, 1});
    }
    for(auto it=mp.begin(); it!=mp.end(); it++)
        answer = answer*((it->second)+1);
    return answer-1;
}