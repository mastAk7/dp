#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int helper(vector<int> &wines, int l, int r){
    // base case
    if(l>r) return 0;

    if(dp[l][r] != -1) return dp[l][r];

    int day = wines.size() - (r-l);

    // recursive case
    int case1 = wines[l] * day + helper(wines,l+1,r);
    int case2 = wines[r] * day + helper(wines,l,r-1);

    return dp[l][r] = max(case1,case2);
}

int iterative(vector<int> &wines){
    int n = wines.size();

    vector<vector<int>> dp(n,vector<int>(n,0));

    for(int day = n; day >= 1; day--){
        for(int l = 0; l < day; l++){
            int r = n + l - day;

            if(day == n) dp[l][r] = wines[l] * day;
            else{
                int opt1 = wines[l] + dp[l+1][r];
                int opt2 = wines[r] + dp[l][r-1];

                dp[l][r] = max(opt1,opt2);
            }
        }
    }

    return dp[0][4];
}

int main(){
    vector<int> wines = {2,4,6,2,5};

    dp.assign(5,vector<int>(5,-1));
    
    cout << helper(wines,2,4) << endl;
}