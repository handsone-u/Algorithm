#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int curw = 0, todo = 0,done = 0, len = truck_weights.size(), on = 0;;
    queue<int> q;
    while(done<len){
        if(answer>=20) break;
        answer++;
        if(q.size()==bridge_length){
            cout<<">"<<q.size()<<endl;
            int tmp = q.front(); q.pop();
            if(tmp>0) {
                curw-=truck_weights[done];
                done++;
            }
        }
        if(todo>=len){
            q.push(0);
            continue;
        }
        if(curw+truck_weights[todo]<=weight){
            curw+=truck_weights[todo];
            q.push(truck_weights[todo++]);
        }
        else
            q.push(0);
    }
    return answer;
}