#include <string>
#include <vector>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int sum = brown+yellow;
    for(int i=3;i*i<=sum;i++){
        int j = sum/i;
        int ti = i-2, tj = j-2;
        if(ti*tj==yellow){
            if(i>j){
                answer.push_back(i);
                answer.push_back(j);
            }
            else{
                answer.push_back(j);
                answer.push_back(i);
            }
            break;
        }
    }
    return answer;
}