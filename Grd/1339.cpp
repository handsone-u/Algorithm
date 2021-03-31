#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int n,a[26],ans;
bool comp(int x,int y){
    return x>y;
}
string s;
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        int l=s.length();
        int cnt=1;
        for(int j=l-1;j>=0;j--){
            char c = s[j]-'A';
            a[c] += cnt;
            cnt*=10;
        }
    }
    sort(a,a+26,comp);
    int cnt = 9;
    for(int i=0;i<10;i++)
        ans+=cnt--*a[i];
    cout<<ans<<'\n';
    return 0;
}