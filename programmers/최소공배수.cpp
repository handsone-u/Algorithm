#include <string>
#include <vector>
using namespace std;

int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b, a%b);
}

int solution(vector<int> arr) {
    int answer = 0, n = arr.size();
    int tlcm = arr[0];
    for(int i=1;i<n;i++){
        int tgcd = gcd(tlcm, arr[i]);
        tlcm = (tlcm*arr[i])/tgcd;
    }
    answer=tlcm;

    return answer;
}