class Solution {
public:
   int MOD = 1e9+7;
   vector<int>prev;
   int dp[2001];
   int solve(int n){
    if(n ==0){ //empty substring 
        return 1;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int total = (solve(n-1)*2)%MOD;
    if(prev[n]!=0){
    int duplicates = solve(prev[n]-1)%MOD;
    total = (total -duplicates+MOD)%MOD;
    }
    return dp[n] = total;
   }
    int distinctSubseqII(string s) {
        int n = s.length();
        memset(dp,  -1, sizeof(dp));
        prev.assign(n+1, 0);
        vector<int>lastseen(26, 0);
        for(int i=1;i<=s.length();i++){
              int idx = s[i-1]-'a';
             prev[i] =  lastseen[idx];
               lastseen[idx] =i;
        }
      return (solve(n)-1+MOD)%MOD;
    }
};