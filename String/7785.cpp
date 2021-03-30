#include<iostream>
#include<set>
#include<string>
using namespace std;
int n;
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    set<string> s;
    cin>>n;
    for(int i=0;i<n;i++){
        string str1,str2;
        cin>>str1>>str2;
        if(str2=="enter"){
            s.insert(str1);
            continue;
        }
        s.erase(str1);
    }
    for(auto r=s.rbegin();r!=s.rend();r++)
        cout<<*r<<'\n';
    return 0;
}