class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;   // store indices
        int water = 0;

        for (int i = 0; i < height.size(); i++) {

            while (!st.empty() && height[i] > height[st.top()]) {

                int bottom = st.top();
                st.pop();

                if (st.empty()) //at the end no water is collected
                
                    break;

                int left = st.top();

                int width = i - left - 1;

                int h = min(height[left], height[i])
                        - height[bottom];

                water += width * h;
            }

            st.push(i);
        }

        return water;
    }
};