class Solution {
public:
    int numOfSubarrays(vector<int>& nums, int k, int threshold) {
        int n = nums.size();
        long long sum=0;
        int left =0;
        unordered_map<int, int>mp;
        int count =0;
        for(int right =0; right<n; right++){
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
            if(right-left+1 ==k && sum/k >=threshold){
                count++;
            }
        }
        return count;
    }
};