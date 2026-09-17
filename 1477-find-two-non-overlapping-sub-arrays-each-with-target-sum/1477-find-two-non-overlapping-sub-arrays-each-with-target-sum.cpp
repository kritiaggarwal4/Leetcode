class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();

        vector<int> prefix(n + 1, INT_MAX);

        int left = 0;
        int sum = 0;
        int ans = INT_MAX;
        int best = INT_MAX;

        for (int right = 0; right < n; right++) {
            sum += arr[right];

            while (sum > target) {
                sum -= arr[left];
                left++;
            }

            if (sum == target) {
                int len = right - left + 1;

                if (prefix[left] != INT_MAX) {
                    ans = min(ans, prefix[left] + len);
                }

                best = min(best, len);
            }

            prefix[right + 1] = best;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};