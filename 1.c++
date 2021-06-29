#include <string>
#include <vector>
#include <iostream>
using namespace std;
string str[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
string tos[10] = {"0","1","2","3","4","5","6","7","8","9"};
bool ck(char c){
    if(c>='0'&&c<='9')
        return true;
    else
        return false;
}

int solution(string s) {
    int answer = 0;
    int len = s.size();

    int i = 0;

    while (i<len) {
        if(ck(s[i])){
            answer= answer*10+(s[i]-'0');
            i++;
            continue;
        }
        string tmp;
        bool found = false;
        while(i<len){
            tmp += s[i++];
            for(int k=0;k<10;k++){
                if(tmp.compare(str[k])==0){
                    answer = answer*10 + k;
                    found=true;
                    break;
                }
            }
            if(found) break;
        }
    }
    

    return answer;
}