#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int len = prices.size();
    for(int i=0;i<len;i++){
        int tmp = prices[i];
        int sec=0;
        for(int j=i+1;j<len;j++){
            sec++;
            if(tmp>prices[j])
                break;
        }
        answer.push_back(sec);
    }
    return answer;
}