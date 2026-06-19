#include <bits/stdc++.h>
using namespace std;

vector<int> dp;

int helper(vector<int> coins, int n){
    // base case
    if(dp[n] != -1) return dp[n];

    if(n==0) return 0;

    // recursive case
    int ans = 1e9;
    for(int i=0; i<coins.size(); i++){
        // agar coin badha h to cannot be reduced
        if(n<coins[i]) continue;

        // coin ghata diya value mei se
        int remaining = n - coins[i];

        // remaining value ke number of coins mangwa liye
        int recur = helper(coins,remaining);

        ans = min(ans,recur);
    }

    return dp[n] = ans + 1;
}

int iterative(vector<int> coins, int n){
    vector<int> dp(n+1,0);

    // base case
    dp[0] = 0;

    for(int i=1; i<=n; i++){
        int ans = 1e9;

        for(int j=0; j<coins.size(); j++){
            if(coins[j] > i) continue;

            ans = min(ans,dp[i-coins[j]]);
        }

        dp[i] = ans;
    }

    if(dp[n] == 1e9) return -1;
    return dp[n];
}

int main(){
    vector<int> coins = {1,4,5};
    int n = 8;

    dp.assign(11+1,-1);

    int ans = helper(coins,n);

    if(ans >= 1e9) cout << -1 << endl;
    cout << ans << endl;
}