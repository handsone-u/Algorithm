#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

vector<int> solution(string code, string day, vector<string> data) {
    vector<int> answer;
    int dsize = data.size(), csize = code.size(), daysize = day.size();
    vector<pair<int, int> > v;
    int icode = stoi(code), iday = stoi(day);

    for(int i=0;i<dsize;i++){
        vector<string> result;
        stringstream ss(data[i]);
        string token;
        int nowsize = data[i].size();

        while(getline(ss, token, ' ')){
            result.push_back(token);
        }

        int info[3];    
        info[0]=stoi(result[0].substr(6));
        info[1]=stoi(result[1].substr(5));
        info[2]=stoi(result[2].substr(5));

        if(icode!=info[1]) continue;
        int date = info[2]/100;
        int month = info[2]%100;
        if(date!=iday) continue;
        v.push_back(make_pair(month, info[0]));
    }
    sort(v.begin(), v.end());
    for(int i=0;i<v.size();i++)
        answer.push_back(v[i].second);

    return answer;
}