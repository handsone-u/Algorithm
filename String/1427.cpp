#include<iostream>
using namespace std;
int n[10];
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    char c;
    while(cin.get(c)){
        if(c=='\n') break;
        int ind = c-'0';
        n[ind]++;
    }
    for(int i=9;i>=0;i--){
        int it =  n[i];
        for(int j=0;j<it;j++) cout<<i;
    }
    return 0;
}