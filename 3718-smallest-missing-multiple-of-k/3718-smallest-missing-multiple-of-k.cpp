class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int ans =-1;
        
         int p = k;

        while(mp.find(p) != mp.end()) {
            p += k;
        }

        return p;
    }
};