#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int p1, p2, p3, len;
    p1 = p2 = p3=0;
    len = answers.size();
    for(int i=0;i<len;i++){
        int a = answers[i];
        int c1 = i%5 + 1;
        int c2 = i%8, n2;
        int c3 = i%10, n3;
        switch (c2)
        {
        case 1:
            n2 = 1;
            break;
        case 3:
            n2 = 3;
            break;
        case 5:
            n2 = 4;
            break;
        case 7:
            n2 = 5;
            break;
        default:
            n2 = 2;
            break;
        }
        switch (c3)
        {
        case 0:
            n3 = 3;
            break;
        case 1:
            n3 = 3;
            break;
        case 2:
            n3 = 1;
            break;
        case 3:
            n3 = 1;
            break;
        case 4:
            n3 = 2;
            break;
        case 5:
            n3 = 2;
            break;
        case 6:
            n3 = 4;
            break;
        case 7:
            n3 = 4;
            break;  
        case 8:
            n3 = 5;
            break;
        case 9:
            n3 = 5;
            break;
        }
        if(c1==a) p1++;
        if(n2==a) p2++;
        if(n3==a) p3++;
    }
    if(p1>p2){
        if(p1>p3) answer.push_back(1);
        else if(p1==p3){
            answer.push_back(1);
            answer.push_back(3);
        }
        else answer.push_back(3);
    }
    else if(p1==p2){
        if(p1>p3){
            answer.push_back(1);
            answer.push_back(2);
        }
        else if(p1==p3){
            answer.push_back(1);
            answer.push_back(2);
            answer.push_back(3);
        }
        else answer.push_back(3);
    }
    else{
        if(p2==p3){
            answer.push_back(2);
            answer.push_back(3);
        }
        else if(p2>p3) 
            answer.push_back(2);
        else
            answer.push_back(3);
    }
    return answer;
}