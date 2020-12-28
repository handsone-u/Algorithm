//
//  main.cpp
//  algorithm
//
//  Created by handsone on 2020/12/27.
//

#include <iostream>
using namespace std;
int dp[41],t,n;

int main(int argc, const char * argv[]) {
    cin>>t;
    dp[0]=0;
    dp[1]=dp[2]=1;
    
    for(int i=3;i<=40;i++) dp[i]=dp[i-1]+dp[i-2];
    
    while(t--){
        cin>>n;
        if(n==0) cout<<"1 0\n";
        else if(n==1) cout<<"0 1\n";
        else cout<<dp[n-1]<<" "<<dp[n]<<"\n";
    }
    return 0;
}
