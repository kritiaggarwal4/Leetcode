class Solution {
public:
    string removeKdigits(string num, int k) {
        //if larger digit comes before a smaller digit remove that digit
        stack<char>st;
        for(int i=0;i<num.length();i++){
            while(!st.empty()&& st.top()>num[i] && k>0){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        //if still k left then remove last digits
        while(!st.empty() && k>0){
            st.pop();
            k--;
        }
      if(st.empty()){
        return "0";
      }
      string res = "";
      while(!st.empty()){
        res.push_back(st.top());
        st.pop();
      }
      while(res.size()>0 && res.back()=='0'){
        res.pop_back();
      }
      reverse(res.begin(), res.end());
      if(res.empty())
      return "0";
      return res;
    }
};