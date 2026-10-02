class Solution {
public:
vector<vector<string>>result;
bool isPalindrome(string &ss){
int i=0;
int j= ss.length()-1;
while(i<=j){
    if(ss[i]!=ss[j])
    return false;
    i++;
    j--;
}
return true;
}
void solve(int i, string &s, vector<string>&ans){
    if(i==s.length()){
       result.push_back(ans);
       return;
    }
    for(int j= i; j<s.length();j++){
        string curr = s.substr(i,j-i+1 );
        if(isPalindrome(curr)){
        ans.push_back(curr);
        solve(j+1, s, ans);
        ans.pop_back();
        }
    }
}
    vector<vector<string>> partition(string s) {
        vector<string>ans;
        solve(0, s, ans);
        return result;
    }
};