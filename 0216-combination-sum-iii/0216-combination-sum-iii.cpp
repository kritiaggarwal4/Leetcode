class Solution {
public:
vector<vector<int>>result;
void solve(int i, vector<int>&arr, vector<int>&ans, int k, int target){
    if(target ==0 && ans.size() ==k ){
      result.push_back(ans);
      return;
    }
     if(target < 0 || ans.size() > k || i >= arr.size())
            return;
    ans.push_back(arr[i]);
    solve(i+1, arr, ans, k, target-arr[i]);
    ans.pop_back();
    solve(i+1, arr, ans, k, target);
}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>arr(9);
        for(int i=0;i<arr.size();i++){
            arr[i] = i+1;
        }
        vector<int>ans;
        solve(0, arr, ans, k, n);
        return result;
    }
};