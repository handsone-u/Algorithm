#include<iostream>
#include<string>
#include<vector>
using namespace std;
string str;
long long dp[5001];
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<int> v;
    cin>>str;
    int len = str.length();
    for(int i=0;i<len;i++){
        int x = str[i]-'0';
        v.push_back(x);
    }  
    dp[0]=1;
    for(int i=0;i<len;i++){
        if(v[i]!=0)
            dp[i+1]=(dp[i+1]+dp[i])%1000000;
        int tmp = v[i]+v[i-1]*10;
        if(10<=tmp&&tmp<=26)
            dp[i+1]=(dp[i+1]+dp[i-1])%1000000;
    }
    cout<<dp[len];
    return 0;
}