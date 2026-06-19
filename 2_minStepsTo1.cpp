// https://www.spoj.com/problems/MST1/
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int topDown(vi &dp, int n){
    // return se pehle store
    // if(n==1) return 0;
    if(n==1) return dp[1]=0;
    
    // calculate se pehle check
    if(dp[n]!=-1) return dp[n];

    int opt1, opt2, opt3;
    opt1=opt2=INT_MAX;
    if(n%3==0) opt1 = topDown(dp,n/3); 
    if(n%2==0) opt2 = topDown(dp,n/2);
    opt3 = topDown(dp,n-1);
    
    // return se pehle store
    return dp[n] = min(opt1,min(opt2,opt3)) + 1;
}

// int bottomUp(vi &dp, int n){
int bottomUp(vi &dp, int n){
    dp[1] = 0;
    for(int i=2; i<=n; i++){
        int opt1, opt2, opt3;
        opt1=opt2=INT_MAX;
        if(i%3==0) opt1 = dp[i/3]; 
        if(i%2==0) opt2 = dp[i/2];
        opt3 = dp[i-1];
        dp[i] = min(opt1,min(opt2,opt3)) + 1;
    }
    return dp[n];
    // return;
}

int main(){
    int t; cin>>t;
    vi test(t);
    for(int i=0; i<t; i++) cin>>test[i];
    int mx = *max_element(test.begin(),test.end());
    vi dp(mx + 1,-1);
    bottomUp(dp,mx);
    for(int i=1; i<=t; i++) cout<<"Case "<<i<<": "<<dp[test[i-1]]<<endl;
}