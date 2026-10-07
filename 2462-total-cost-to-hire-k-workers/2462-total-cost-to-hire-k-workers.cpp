class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> left;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> right;

        int n = costs.size();

        for(int i = 0; i < candidates && i < n; i++) {
            left.push({costs[i], i});
        }

        for(int i = n - 1; i >= n - candidates && i >= candidates; i--) {
            right.push({costs[i], i});
        }

        long long ans = 0;
        int j = 0;
        int l = candidates;
        int r = n - candidates - 1;

        while(k > 0) {
            if(right.empty() || (!left.empty() && left.top() <= right.top())) {
                ans += left.top().first;
                left.pop();

                if(l <= r) {
                    left.push({costs[l], l});
                    l++;
                }
            }
            else {
                ans += right.top().first;
                right.pop();

                if(l <= r) {
                    right.push({costs[r], r});
                    r--;
                }
            }

            k--;
        }

        return ans;
    }
};