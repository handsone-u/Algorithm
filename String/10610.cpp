#include<iostream>
using namespace std;
int num[10],l,sum;
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    char c;
    while(cin.get(c)){
        if(c=='\n') break;
        int ind = c-'0';
        sum+=ind;
        num[ind]++;
    }
    if(sum%3||num[0]==0){
        cout<<-1<<'\n';
        return 0;
    }
    for(int i=9;i>=0;i--){
        int x = num[i];
        for(int j=0;j<x;j++) cout<<i;
    }
    cout<<'\n';
    return 0;
}