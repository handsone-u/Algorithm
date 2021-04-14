#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
long long cal(long long a,long long b,char op){
    if(op=='+') return a+b;
    if(op=='-') return a-b;
    if(op=='*') return a*b;
}
long long solution(string expression) {
    long long answer = 0, n = expression.size();
    vector<long long> nums;
    vector<char> ops, pres;
    long long number=0;
    for(int i=0;i <n;i++){
        if(expression[i]>'9'||expression[i]<'0'){
            nums.push_back(number);
            number=0;
            ops.push_back(expression[i]);
        }
        else{
           number *= 10;
           number += expression[i]-'0';
        }
    }
    nums.push_back(number);
    pres = ops;
    sort(pres.begin(), pres.end());
    pres.erase(unique(pres.begin(),pres.end()), pres.end());
    do {
        vector<long long> tnums = nums;
        vector<char> tops = ops;
        long long tans=0, psize=pres.size();
        for(int i=0;i<psize;i++){
            char tmpop = pres[i];
            int k = 0;
            while(k<tops.size()){
                if(tops[k]!=tmpop){
                    k++;
                    continue;
                }
                long long tmpcal = cal(tnums[k], tnums[k+1], tmpop);
                tops.erase(tops.begin()+k);
                tnums.erase(tnums.begin()+k);
                tnums.erase(tnums.begin()+k);
                tnums.insert(tnums.begin()+k, tmpcal);
            }
        }
        tans = abs(tnums[0]);
        if(tans>answer) answer=tans;
    } while (next_permutation(pres.begin(),pres.end()));
    
    return answer;
}