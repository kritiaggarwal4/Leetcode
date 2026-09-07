class Solution {
public:
int solve(vector<vector<int>>&dp, string &s, string &t, int m, int n){

    if(n ==0){
        return 1;
    }
    if(m ==0){
        return 0;
    }
    if(dp[n][m]!=-1){
        return dp[n][m];
    }
    if(s[m-1]== t[n-1]){
        return dp[n][m] = solve(dp, s, t, m-1, n-1)+ solve(dp, s,t, m-1, n);
    }
    else{
        return dp[n][m]= solve(dp, s, t, m-1, n);
    }
}
    int numDistinct(string s, string t) {
      int m = s.length();
      int n = t.length();
      vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
      return solve(dp, s, t, m ,n);
    }
};