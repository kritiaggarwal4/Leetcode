class Solution {
public:
    int minAddToMakeValid(string s) {
      stack<char>st;
      int n =  s.length();
      int i=0;
      if(n ==0){
        return 0;
      }
      while(i<n){
        if(s[i] == '('){
            st.push(s[i]);
        }
        else if(!st.empty() && s[i] == ')' && st.top() == '('){
            st.pop();
        }
        else if(s[i] == ')'){
            st.push(s[i]);
        }
        i++;
      }
      return st.size();
    }
};