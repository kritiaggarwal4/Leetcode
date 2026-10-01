class Solution {
public:
vector<string>result;
void generate( int n, string &ans, int open, int close ){
    if(ans.size() == 2*n){
        result.push_back(ans);
        return;
    }
    if(open<n){
        ans+='(';
        generate(n , ans, open+1, close);
        ans.pop_back();
    }
    if(close<open){
        ans+=')';
        generate(n, ans, open, close+1);
        ans.pop_back();
    }
}
    vector<string> generateParenthesis(int n) {
        string ans = "";
        generate(n, ans, 0, 0);
        return result;
    }
};