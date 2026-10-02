class Solution {
public:
vector<string>res;
void solve(int i, string mapping[], string &digits, string output){
    if(i == digits.size()){
        res.push_back(output);
        return;
    }
    int num = digits[i] - '0';
    string value = mapping[num];
      for(int j=0;j<value.length();j++){
        output.push_back(value[j]);
        solve(i+1, mapping, digits, output);
        output.pop_back();
      }
}
    vector<string> letterCombinations(string digits) {
        string output = "";
        if(digits.length() ==0){
           return res;
        }
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
      solve(0, mapping, digits, output);
      return res;
    }
};