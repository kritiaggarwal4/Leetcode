class Solution {
public:
vector<vector<int>>result;
void solve(int i, vector<int>&nums, vector<int>&ans){
int n = nums.size();
if(i==n){
    result.push_back(ans);
    return;
}
ans.push_back(nums[i]);
solve(i+1, nums, ans);
ans.pop_back();
solve(i+1, nums, ans);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>ans;
        solve(0, nums, ans);
        return result;
    }
};