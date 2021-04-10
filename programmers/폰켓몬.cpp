#include <vector>
using namespace std;
int puki[200001];
int solution(vector<int> nums){
    int answer = 0;
    int len = nums.size();
    for(int i=0;i<len;i++){
        if(puki[nums[i]]) continue;
        answer++;
        puki[nums[i]]++;
    }
    if(answer>len/2) answer=len/2;
    return answer;
}