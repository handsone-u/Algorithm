#include <string>
#include <vector>
#include <sstream>
using namespace std;

string solution(string s) {
    int n = s.size();
    int dif = 'a'-'A';
    bool space = true;
    for(int i=0;i<n;i++){
        if(s[i]==' '){
            space=true;
            continue;
        }
        if(space){
            space=false;
            if(s[i]>='a'&&s[i]<='z')
                s[i]-=dif;
        }
        else{
            if(s[i]>='A'&&s[i]<='Z')
                s[i]+=dif;
        }
    }
    return s;
}