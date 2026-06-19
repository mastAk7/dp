#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int helper(string& s1, string& s2, int n, int m, int i, int j){
    if(dp[i][j] != -1) return dp[i][j];

    // base case
    if(i==n || j==m) return 0;


    // recursive case
    if(s1[i] == s2[j]) return dp[i][j] = 1 + helper(s1,s2,n,m,i+1,j+1);

    int case1 = helper(s1,s2,n,m,i+1,j);
    int case2 = helper(s1,s2,n,m,i,j+1);
    int case3 = helper(s1,s2,n,m,i+1,j+1);

    return dp[i][j] = max(case1,max(case2,case3));
}

int main(){
    string s1 = "abcde";
    string s2 = "adce";

    int n = s1.size();
    int m = s2.size();

    dp.assign(n+1,vector<int>(m+1,-1));
    
    cout << helper(s1,s2,n,m,0,0);
}