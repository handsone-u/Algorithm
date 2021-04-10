#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int len = arr.size();
    int now = -1;
    for(int i=0;i<len;i++){
        if(now!=arr[i]){
            now=arr[i];
            answer.push_back(now);
        }
    }
    return answer;
}