#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<long long> a;
queue<long long> q;
void func(long long x){
    long long r = x%10;
    x*=10;
    for(int i=0;i<r;i++){
        long long tmp = x+i;
        a.push_back(tmp);
        q.push(tmp);
    }
}

int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long n;
    cin>>n;
    if(n<10){
        cout<<n;
        return 0;
    }
    for(int i=0;i<10;i++) {
        a.push_back(i);
        q.push(i);
    }
    while(!q.empty()){
        long long tmp = q.front();
        q.pop();
        func(tmp);
    }
    if(n<a.size()) cout<<a[n];
    else cout<<-1;
    return 0;
}