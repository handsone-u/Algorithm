#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<vector<int> > routes) {
    int answer = 0, rsize = routes.size();
    sort(routes.begin(), routes.end());

    int it = 0;
    while(it<rsize){
        int ent = routes[it][0], pass = routes[it][1];
        int next = ++it;
        while(next<rsize){
            int next_ent = routes[next][0], next_pass = routes[next][1];
            if(pass<next_ent) break;
            pass = min(pass, next_pass);
            next++;
        }
        it = next;
        answer++;
    }

    return answer;
}