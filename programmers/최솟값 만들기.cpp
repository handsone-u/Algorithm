#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0, n = A.size();
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    for(int i=0;i<n;i++){
        int tmp = A[i]*B[n-1-i];
        answer+=tmp;
    }
    return answer;
}