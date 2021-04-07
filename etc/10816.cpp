#include<iostream>
#include<unordered_map>
using namespace std;
int n,m;
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    unordered_map<int, int> map;
    cin>>n;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        map[x]++;
    }
    cin>>m;
    for(int i=0;i<m;i++){
        int x; cin>>x;
        cout<<map[x]<<' ';
    }
    return 0;
}