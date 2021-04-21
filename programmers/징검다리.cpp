#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0, rsize = rocks.size();
    int left=1, right=distance;
    sort(rocks.begin(), rocks.end());
    while(left<=right){
        int mid = (left+right)/2;
        int gone=0, prev=0;
        for(int i=0;i<rsize;i++){
            if(mid>rocks[i]-prev) gone++;
            else prev=rocks[i];
        }
        if(mid>distance-prev) gone++;
        if(gone>n) right=mid-1;
        else{
            answer=max(answer, mid);
            left=mid+1;
        }
    }
    return answer;
}