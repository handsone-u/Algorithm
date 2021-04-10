#include <string>
#include <vector>
using namespace std;
bool d[1000001];
int solution(int n) {
    int answer = 0;
    d[1]=true;
    for(int i=2;i<=n;i++){
        if(d[i]==true) continue;
        d[i]=false;
        for(int j=2;j*i<=n;j++)
            d[j*i]=true;
    }
    for(int i=2;i<=n;i++)
        if(!d[i]) answer++;
    return answer;
}