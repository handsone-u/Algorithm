#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    // # auto sort by key
    // # unique key
    map<string ,int> m1; // (acending)
    map<string ,int, greater<string> > m2; // (decending)
    // # arg : pair
    m1.insert(make_pair("taylor", 100));
    m1.insert(make_pair("show", 12));
    m1.insert(make_pair("apple", 4));
    m1.insert(make_pair("tod", 523));
    m1.insert(make_pair("son", 2));
    m1.insert(make_pair("bear", 14));
    m1.insert(make_pair("zeta", 46));
    m2.insert(make_pair("taylor", 100));
    m2.insert(make_pair("show", 12));
    m2.insert(make_pair("apple", 4));
    m2.insert(make_pair("tod", 523));
    m2.insert(make_pair("son", 2));
    m2.insert(make_pair("bear", 14));
    m2.insert(make_pair("zeta", 46));

    // # travers
    for(auto it :m1)
        cout<<it.first<<' '<<it.second<<endl;
    // for(auto it=m1.begin(); it!=m1.end(); it++)
    //     cout<<(*it).first<<' '<<(*it).second<<endl;
    // for(auto it=m1.begin(); it!=m1.end(); it++)
    //     cout<<it->first<<' '<<it->second<<endl;
    cout<<endl;

    // # [key] operator : access by key 
    cout<<"key-son :"<<m1["son"]<<endl;
    cout<<"key-no exist :"<<m1["asfa"]<<endl;
    cout<<"key-son :"<<m1.count("son")<<endl;
    cout<<"key-no exist :"<<m1.count("asfs")<<endl;

    // # search by key
    auto it = m1.find("son");
    if(it==m1.end()) cout<<"son not found.\n";
    else cout<<"found & value :"<<(*it).second<<endl;

    // # erase by addrs
    m1.erase(it);
    it = m1.find("son");
    if(it==m1.end()) cout<<"son not found.\n";
    else cout<<"found & value :"<<(*it).second<<endl;

    return 0;
}   