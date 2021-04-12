#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0, n = citations.size();
    sort(citations.begin(), citations.end());
    int m = *max_element(citations.begin(), citations.end());
    int z = *min_element(citations.begin(), citations.end());
    int h=0;
    for(int i=0;i<=m;i++){
        int th=-1;;
        for(int j=0;j<n;j++){
            if(citations[j]>=i){
                th=j;
                break;
            }
        }
        if(n-th>=i&&th<=i){
            h=i;
        }
    }
    answer=h;
    return answer;
}