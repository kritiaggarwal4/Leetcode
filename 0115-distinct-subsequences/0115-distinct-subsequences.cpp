class Solution {
public:
// int solve(vector<vector<int>>&dp, string &s, string &t, int m, int n){

//     if(n ==0){
//         return 1;
//     }
//     if(m ==0){
//         return 0;
//     }
//     if(dp[n][m]!=-1){
//         return dp[n][m];
//     }
//     if(s[m-1]== t[n-1]){
//         return dp[n][m] = solve(dp, s, t, m-1, n-1)+ solve(dp, s,t, m-1, n);
//     }
//     else{
//         return dp[n][m]= solve(dp, s, t, m-1, n);
//     }
// }
    int numDistinct(string s, string t) {
       int m = s.length();
        int n = t.length();

        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));

        // Empty t can be formed in exactly 1 way
        for(int i = 0; i <= m; i++) {
            dp[i][0] = 1;
        }

        // Empty s cannot form a non-empty t
        for(int j = 1; j <= n; j++) {
            dp[0][j] = 0;
        }

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {

                if(s[i-1] == t[j-1]) {
                    dp[i][j] = min(1LL * INT_MAX,
                   dp[i-1][j-1] + dp[i-1][j]);
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[m][n];
     // return solve(dp, s, t, m ,n);
    }
};