#include<iostream>
#include<string>
#include<deque>
using namespace std;
int t;
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>t;
    while (t--){
        string str; cin>>str;
        int n; cin>>n;
        char c; cin>>c;
        bool flag = true, rev = false;
        deque<int> deq;
        for(int i=0;i<n;i++){
            int x; cin>>x;
            deq.push_back(x);
            if(i+1!=n) cin>>c;
        }
        cin>>c;

        int len = str.size();
        for(int i=0;i<len;i++){
            if(str[i]=='R'){
                if(rev) rev=false;
                else rev=true;
                continue;
            }
            int dsize = deq.size();
            if(dsize==0){
                flag=false;
                break;
            }
            if(rev) deq.pop_back();
            else deq.pop_front();
        }
        if(flag){
            cout<<'[';
            int dsize = deq.size();
            if(rev){
                for(int i=dsize-1;i>=0;i--){
                    cout<<deq[i];
                    if(i-1>=0) cout<<',';
                }
            }
            else{
                for(int i=0;i<dsize;i++){
                    cout<<deq[i];
                    if(i+1<dsize) cout<<',';
                }
            }
            cout<<"]\n";
        }
        else cout<<"error\n";
    }
    
    return 0;
}