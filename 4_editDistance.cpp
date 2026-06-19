#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int cost(string &s1, string &s2, int n, int m, int i, int j){
    if(dp[i][j] != -1) return dp[i][j]; 

    // base case
    if(i==n) return m-j;
    if(j==m) return n-i;

    // recursive case

    if(s1[i] == s2[j]) return cost(s1,s2,n,m,i+1,j+1);

    int ans = 1e9;

    ans = min(ans,cost(s1,s2,n,m,i+1,j)); // delete
    ans = min(ans,cost(s1,s2,n,m,i,j+1)); // insert
    ans = min(ans,cost(s1,s2,n,m,i+1,j+1)); // replace

    return dp[i][j] = ans + 1;
}

int iterative(string &s1, string &s2){
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n+1,vector<int>(m+1));

    // base case:
    // j hamara m ban chuka h
    // to hum i ki saari values par iterate kar rahe
    for(int i=0; i<=n; i++) dp[i][m] = n - i;
    
    // i hamara n ban chuka h
    // to hum j ki saari values par iterate kar rahe
    for(int j=0; j<=m; j++) dp[n][j] = m - j;

    for(int i=n-1; i>=0; i--){
        for(int j=m-1; j>=0; j--){
            // elements equal h so no need for any operation
            if(s1[i] == s2[j]) dp[i][j] = dp[i+1][j+1];
            else{

                // yaha ek operation krna padega
                dp[i][j] = min(dp[i+1][j+1],min(dp[i+1][j],dp[i][j+1])) + 1;
            }
        }
    }

    return dp[0][0];
}

int main(){
    string s1 = "saturday";
    string s2 = "sunday";

    int n = s1.size();
    int m = s2.size();

    dp.assign(n+1,vector<int>(m+1,-1));

    cout << cost(s1,s2,n,m,0,0);
}