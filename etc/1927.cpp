#include<iostream>
#include<queue>
using namespace std;
int n;
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    priority_queue<int, vector<int>, less<int> > q;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x==0){
            if(q.empty()){
                cout<<0<<'\n';
                continue;
            }
            cout<<q.top()<<'\n';
            q.pop();
            continue;
        }
        q.push(x);
    }
    return 0;
}