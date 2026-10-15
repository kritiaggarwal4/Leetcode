
class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<int, int> mp;
            int distinct = 0;

            for (int j = i; j < n; j++) {
                if (mp[nums[j]] == 0) {
                    distinct++;
                }

                mp[nums[j]]++;

                ans += distinct * distinct;
            }
        }

        return ans;
    }
};
