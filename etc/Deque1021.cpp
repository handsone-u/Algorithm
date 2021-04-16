#include<iostream>
#include<vector>
using namespace std;
int n,m,ans,num[51];
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;
    vector<int> v;
    for(int i=0;i<m;i++)
        cin>>num[i];
    for(int i=1;i<=n;i++)
        v.push_back(i);
    int cnt=0;
    while(cnt<m){
        int now = num[cnt++];
        int f = v.front(),b = v.back();
        int toup, todown, vsize=v.size();
        for(int i=0;i<vsize;i++){
            if(v[i]==now){
                toup=i;
                break;
            }
        }
        for(int i=vsize-1;i>=0;i--){
            if(v[i]==now){
                todown=vsize-i;
                break;
            }
        }
        if(toup<todown){
            for(int i=0;i<toup;i++){
                v.push_back(v.front());
                v.erase(v.begin());
            }
            v.erase(v.begin());
            ans+=toup;
        }
        else{
            for(int i=0;i<todown;i++){
                v.insert(v.begin(), v.back());
                v.erase(v.end()-1);
            }
            v.erase(v.begin());
            ans+=todown;
        }
    }
    cout<<ans;
    return 0;
}