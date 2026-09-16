class Solution {
public:
    int solve(int n, int m, string &str1, string & str2, vector<vector<int>>&dp){
        if(n ==0|| m ==0){
            return 0;
        }
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        if(str1[n-1] == str2[m-1]){
           dp[n][m] = 1+solve(n-1, m-1, str1, str2, dp);
        }
        else{
            dp[n][m] = max(solve(n-1, m, str1, str2, dp), solve(n, m-1, str1, str2, dp));
        }
    return dp[n][m];
    }
    
    string shortestCommonSupersequence(string str1, string str2) {
        string ans = "";
        int i= str1.length();
        int j = str2.length();
        vector<vector<int>>dp(i+1, vector<int>(j+1, -1));
        solve(i, j, str1, str2, dp);
        while(i>0 && j>0){
            if(str1[i-1] == str2[j-1]){
                ans+=str1[i-1];
                i--;
                j--;
            }
            else{
                if(dp[i-1][j]>dp[i][j-1]){
                    ans+=str1[i-1];
                    i--;
                }
                else{
                    ans+=str2[j-1];
                    j--;
                }
            }
        }
            while(i>0){
                ans+=str1[i-1];
                i--;
            }
            while(j>0){
                ans+=str2[j-1];
                j--;
            }
            reverse(ans.begin(), ans.end());
        return ans;
    }
};