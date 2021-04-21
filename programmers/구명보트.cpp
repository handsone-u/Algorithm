#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0, n = people.size();

    sort(people.begin(), people.end());

    int i=0, j=n-1;
    while(i<=j){
        int tmp = people[i]+people[j];
        if(tmp<=limit)
            i++, j--;
        else
            j--;
        answer++;
    }
    return answer;
}