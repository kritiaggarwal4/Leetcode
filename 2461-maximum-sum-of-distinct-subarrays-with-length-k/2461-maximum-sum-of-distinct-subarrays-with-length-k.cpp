class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        int left =0;
        int n = nums.size();
        long long maxsum =0;
        long long sum =0;
       for(int right =0; right<n;right++){
        mp[nums[right]]++;
        sum+=nums[right]; 
        if(right-left+1>k){
            mp[nums[left]]--;
            if(mp[nums[left]] ==0){
                mp.erase(nums[left]);
            }
            sum-=nums[left];
            left++;
        }
       if(right-left+1 ==k && mp.size() ==k){
        maxsum = max(maxsum, sum);
       }
       }
       return maxsum;
    }
};