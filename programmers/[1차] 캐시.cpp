#include <string>
#include <vector>
#include <map>
using namespace std;
void makelow(vector<string> &t, int len){
    int dif = 'a'-'A';
    for(int i=0;i<len;i++){
        int tlen = t[i].size();
        for(int j=0;j<tlen;j++){
            if(t[i][j]>='A'&&t[i][j]<='Z')
                t[i][j] += dif;
        }
    }
}
int solution(int cacheSize, vector<string> cities) {
    int answer = 0, n = cities.size();
    if(cacheSize==0){
        answer = 5*n;
        return answer;
    }
    makelow(cities,n);
    map<string, int> mp;
    for(int i=0;i<n;i++){
        auto it = mp.find(cities[i]);
        if(it!=mp.end()){
            mp[cities[i]]=i;
            answer++;
            continue;
        }
        else if(mp.size()<cacheSize){
            mp.insert(make_pair(cities[i], i));
        }
        else{
            int time = n+1;
            string key;
            for(auto it=mp.begin();it!=mp.end();it++){
                if(it->second<time){
                    time = it->second;
                    key = it->first;
                }
            }
            mp.erase(key);
            mp.insert(make_pair(cities[i], i));
        }
        answer+=5;
    }
    return answer;
}