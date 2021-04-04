#include<iostream>
#include<algorithm>
using namespace std;
int n,zero,a[10000],sum,neg;
bool comp(int x,int y){
    return x>y;
}
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        if(a[i]==0) zero++;
        else if(a[i]<0) neg++;
    }

    sort(a,a+n,comp);
    int it = n-1;
    while(neg>=2){
        sum+= a[it]*a[it-1];
        it -= 2;
        neg -= 2;
    }
    if(neg>0){
        if(zero>0) sum+=0;
        else sum+=a[it];
        it--;
    }
    for(int i=0;i<=it;i++){
        if(i+1>it) {
            sum+=a[i];
            continue;
        }
        if(a[i+1]==0||a[i+1]==1){
            sum+=a[i];
            continue;
        }
        if(a[i]==1){
            sum+=1;
            continue;
        }
        if(a[i]==0) break;
        sum+=a[i]*a[i+1];
        i++;
    }
    cout<<sum<<'\n';
    return 0;
}