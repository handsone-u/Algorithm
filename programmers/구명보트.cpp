#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0, n = people.size();
    sort(people.begin(), people.end());
    int i=0, j=n-1;
    while(i<=j){
        if(i==j){
            answer++;
            break;
        }
        if(people[i]+people[j]<=limit){
            i++; j--;
            answer++;
        }
        else{
            j--;
            answer++;
        }
    }
    return answer;
}