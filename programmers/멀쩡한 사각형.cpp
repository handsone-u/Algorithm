#include<vector>
using namespace std;

long long gcd(long x, long y){
    if(y==0) return x;
    return gcd(y, x%y);
}

long long solution(int w,int h) {
    long long x=w, y=h;
    long long answer = 0;
    long long g = gcd(x,y);
    answer = x*y - (x+y-g);
    return answer;
}