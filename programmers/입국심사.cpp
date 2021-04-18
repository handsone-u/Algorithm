#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0, p = times.size();
    sort(times.begin(), times.end());
    long long start = times[0], end = times[p-1]*(long long)n;
    answer = end;
    while(start<=end){
        long long m = (start+end)/2;
        // cout<<start<<' '<<end<<' '<<m;
        long long val = 0;
        for(int i=0;i<p;i++)
            val += m/times[i];
        // cout<<" : "<<val<<endl;
        if(val>=n){
            if(answer>m)
                answer = m;
            end= m-1;
        }
        else
            start = m+1;
    }
    return answer;
}