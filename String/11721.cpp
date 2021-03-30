#include<iostream>
#include<string>
using namespace std;
string str;
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>str;
    int l = str.length();
    for(int i=0;i<l;i++){
        if(i%10==0&&i>0) cout<<'\n';
        cout<<str[i];
    }
    return 0;
}