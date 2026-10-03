class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size();

        vector<int> res(n - k + 1, 0);
        vector<int> freq(51, 0);

        int start = 0;
        int end = 0;
        int index = 0;

        while (end < n) {

            // Add current element
            if (nums[end] < 0) {
                freq[nums[end] + 50]++;
            }

            // Window is smaller than k
            if (end - start + 1 < k) {
                end++;
                continue;
            }

            // Window size == k
            int count = 0;

            for (int value = -50; value <= -1; value++) {
                count += freq[value + 50];

                if (count >= x) {
                    res[index] = value;
                    break;
                }
            }

            index++;

            // Remove element going out of window
            if (nums[start] < 0) {
                freq[nums[start] + 50]--;
            }

            start++;
            end++;
        }

        return res;
    }
};