#include<iostream>
#include<algorithm>
using namespace std;
int n,x,ans;
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int a[100001];
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    cin>>x;
    int i=0, j=n-1;
    while(i<j){
        int tmp = a[i]+a[j];
        if(tmp==x){
            ans++;
            i++,j--;
        }
        else if(tmp>x){
            j--;
        }
        else{
            i++;
        }
    }
    cout<<ans;
    return 0;
}