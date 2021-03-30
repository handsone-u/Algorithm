#include<iostream>
#include<string>
using namespace std;
string s1,s2;
int ans;
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    getline(cin,s1);
    getline(cin,s2);
    int l1=s1.length(),l2=s2.length();
    int i=0;
    while(i<l1){
        auto t = s1.find(s2,i);
        if(t==string::npos) break;
        i=t+l2;
        ans++;
    }
    cout<<ans<<'\n';
    return 0;
}