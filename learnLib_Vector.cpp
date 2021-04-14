#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int torand(int x){
    int tmp = x*124152;
    return tmp%503;
}

void vprint(vector<int> &tmp){
    cout<<"inorder : ";
    for(auto it = tmp.begin(); it!= tmp.end(); it++) // travers
        cout<<*it<<' ';
    cout<<endl;
}
void rprint(vector<int> &tmp){
    cout<<"reverse : ";
    for(auto it = tmp.rbegin(); it!= tmp.rend(); it++) // travers in reverse way
        cout<<*it<<' ';
    cout<<endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n = 10;
    vector<int> v1;
    for(int i=0;i<n;i++)
        v1.push_back(torand(i));
    v1.clear();
    // better
    for(int i=10;i<n+10;i++)
        v1.emplace_back(torand(i));

    vprint(v1);
    rprint(v1);

    if(v1.at(0)==v1[0])
        cout<<"Same\n";
    // at(i) : check if out of range
    // operator [] : non-check 
    // eg) v1[11] -> error

    cout<<"front : "<<v1.front()<<' ';
    cout<<"back : "<<v1.back()<<endl;;

    // addrs , value
    vprint(v1);
    v1.insert(v1.begin()+1, -1);
    vprint(v1);
    v1.insert(v1.end()-1, -1);
    vprint(v1);
    // addrs , (opt) addrs : [addrs1, addrs2)
    v1.erase(v1.begin()+1);
    v1.erase(v1.end()-2);
    vprint(v1);
    v1.erase(v1.begin()+3, v1.begin()+5);
    vprint(v1);

    sort(v1.begin(), v1.end());
    vprint(v1);

    sort(v1.rbegin(), v1.rend());

    // unique
    vprint(v1);
    
}