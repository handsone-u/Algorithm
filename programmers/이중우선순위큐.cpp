#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    int n = operations.size();
    vector<int> v;

    for(int i=0;i<n;i++){
        char op = operations[i][0];
        int num = stoi(operations[i].substr(2));
        if(op=='I'){
            v.push_back(num);
            sort(v.begin(), v.end());
        }
        else{
            if(v.empty()) continue;
            if(num==-1){
                v.erase(v.begin());
            }
            else{
                int size = v.size();
                v.erase(v.begin()+size-1);
            }
        }
    }
    int size = v.size();
    if(size){
        answer.push_back(v[size-1]);
        answer.push_back(v[0]);
    }
    else{
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}