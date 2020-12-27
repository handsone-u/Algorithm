//
//  main.cpp
//  algorithm
//
//  Created by handsone on 2020/12/27.
//

#include <iostream>
using namespace std;
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
int dp[5001];

int main(int argc, const char * argv[]) {
    
    int x,i,l,r;
    cin >> x;
    dp[1]=dp[2]=dp[4]=-1;
    dp[3]=dp[5]=1;
    
    for(i=6;i<=x;i++)
    {
        l = dp[i-3]+1;
        r = dp[i-5]+1;
        if(!l&&!r) dp[i] = -1;
        else if(l&&!r) dp[i] = l;
        else if(!l&&r) dp[i] = r;
        else dp[i] = MIN(l,r);
    }
    
    cout<<dp[x]<<endl;
    
    return 0;
}
