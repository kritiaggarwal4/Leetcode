class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minIdx = 0, maxIdx = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] < nums[minIdx])
                minIdx = i;

            if (nums[i] > nums[maxIdx])
                maxIdx = i;
        }

        // Make minIdx the smaller index
        if (minIdx > maxIdx)
            swap(minIdx, maxIdx);

        // 1. Remove both from left
        int left = maxIdx + 1;

        // 2. Remove both from right
        int right = n - minIdx;

        // 3. Remove min from left, max from right
        int leftRight = (minIdx + 1) + (n - maxIdx);

        // 4. Remove max from left, min from right
        int rightLeft = (maxIdx + 1) + (n - minIdx);

        return min({left, right, leftRight, rightLeft});
    }
};