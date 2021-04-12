#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

int func(vector<int> &t, int w){
    int len = t.size();
    int res = 0;
    for(int i=0; i<=w;i++){
        res *= 10;
        res += t[i];
    }
    int rt = sqrt(res);
    for(int i=2;i<=rt;i++){
        if(res%i==0){
            res=0;
            break;
        }
    }
    return res;
}

int solution(string numbers) {
    int answer = 0,len = numbers.size();
    vector<int> arr;
    set<int> s;
    for(int i=0;i<len;i++){
        int x = numbers[i]-'0';
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end());
    do{
        for(int i=0;i<len;i++){
            int tmp = func(arr, i);
            if(tmp<=1) continue;
            if(s.insert(tmp).second)
                answer++;
        }
    } while(next_permutation(arr.begin(), arr.end()));

    return answer;
}