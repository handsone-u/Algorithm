#include<iostream>
#include<string>
using namespace std;
string s1,s2;
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>s1>>s2;
    int l1=s1.length(), l2=s2.length();
    int gap = l2-l1, mini = INT32_MAX;
    for(int i=0;i<=gap;i++){
        int tmp = 0;
        for(int j=0;j<l1;j++)
            if(s2[i+j]!=s1[j])
                tmp++;
        if(tmp<mini) mini = tmp;
    }
    cout<<mini<<'\n';
    return 0;
}