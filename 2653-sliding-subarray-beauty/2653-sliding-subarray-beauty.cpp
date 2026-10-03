class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> res(n - k + 1, 0);

        unordered_map<int, int> freq;

        int start = 0;
        int end = 0;
        int index = 0;

        while (end < n) {

            if (nums[end] < 0) {
                freq[nums[end]]++;
            }

            if (end - start + 1 < k) {
                end++;
                continue;
            }

            // find xth smallest negative
            int count = 0;

            for (int i = -50; i <= -1; i++) {
                count += freq[i];

                if (count >= x) {
                    res[index] = i;
                    break;
                }
            }

            index++;

            // remove starting element
            if (nums[start] < 0) {
                freq[nums[start]]--;
            }

            start++;
            end++;
        }

        return res;
    }
};