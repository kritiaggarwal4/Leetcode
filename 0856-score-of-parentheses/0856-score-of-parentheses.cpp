class Solution {
public:
    int balancedParanthesis(string s) {
        stack<char> st;
        int count = 0;
        int depth = 0;

        for (int i = 0; i < s.length(); i++) {

            if (s[i] == '(') {
                st.push('(');
                depth++;
            }
            else {
                if (s[i - 1] == '(') {
                    count += pow(2, depth - 1);
                }

                st.pop();
                depth--;
            }
        }
        return count;
    }

    int scoreOfParentheses(string s) {
        return balancedParanthesis(s);
    }
};