#include<iostream>
#include<set>
using namespace std;
int n;
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    multiset<int> ms;

    for(int i=0;i<n;i++){
        int x; cin>>x;
        ms.insert(x);
        int size = ms.size();
        cout<<ms[0]<<endl;
    }
    return 0;
}