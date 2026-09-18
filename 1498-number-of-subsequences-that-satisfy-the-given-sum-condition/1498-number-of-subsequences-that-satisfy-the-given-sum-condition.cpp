class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0;
        int j = n - 1;
        long long count = 0;
        int MOD = 1e9 + 7;

        sort(nums.begin(), nums.end());

        // power[k] = 2^k % MOD
        vector<long long> power(n);

        power[0] = 1;

        for(int k = 1; k < n; k++) {
            power[k] = (power[k - 1] * 2) % MOD;
        }

        while(i <= j) {
            if(nums[i] + nums[j] <= target) {
                count = (count + power[j - i]) % MOD;
                i++;
            }
            else {
                j--;
            }
        }

        return count;
    }
};