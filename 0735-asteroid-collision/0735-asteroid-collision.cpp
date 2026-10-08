class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        vector<int> ans;

        int i = 0;

        while(i < asteroids.size()) {

            if(st.empty()) {
                st.push(asteroids[i]);
                i++;
            }

            else if(st.top() > 0 && asteroids[i] < 0) {

                if(abs(st.top()) < abs(asteroids[i])) {
                    st.pop();
                }

                else if(abs(st.top()) == abs(asteroids[i])) {
                    st.pop();
                    i++;
                }

                else {
                    i++;
                }
            }

            else {
                st.push(asteroids[i]);
                i++;
            }
        }

        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};