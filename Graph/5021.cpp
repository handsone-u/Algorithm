#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;
int n,m;
map<string, vector<string> > fam;
map<string, double> blood;
string king;
double dfs(string str){
    if(fam[str].empty()) return blood[str];
    string p1 = fam[str][0];
    string p2 = fam[str][1];
    double bld = (dfs(p1) + dfs(p2)) / 2;
    blood[str]=bld;
    return bld;
}
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;
    cin>>king;
    for(int i=0;i<n;i++){
        string child, p1, p2;
        cin>>child>>p1>>p2;
        fam[child].push_back(p1);
        fam[child].push_back(p2);
        blood[child]=blood[p1]=blood[p2]=0;
    }
    string ans;
    double trueblood=0;
    for(int i=0;i<m;i++){
        string candi;
        cin>>candi;
        for(auto ele : blood) ele.second=0;
        blood[king]=1;
        double tmp = dfs(candi);
        if(tmp>trueblood){
            trueblood=tmp;
            ans=candi;
        }
    }
    cout<<ans<<'\n';
    return 0;
}