#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    // iostream : c++ speed up
    // STL
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<int> v;
    int len=1;
    for(int i=1;i<=4;i++)
        v.push_back(i);
    do{
        cout<<len++<<" : ";
        for(int i=0;i<4;i++)
            cout<<v[i]<<' ';
        cout<<endl;
    }while(next_permutation(v.begin(), v.end()));
    v.push_back(4);

    return 0;
}