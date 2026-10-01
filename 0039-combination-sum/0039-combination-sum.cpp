class Solution {
public:
   vector<vector<int>>res;
   void comb(vector<int>& candidates, int target, int i, vector<int>&ans){
    if(target ==0){
      res.push_back(ans);
      return;
    }
    if(target<0 || i== candidates.size()){
        return;
    }
    ans.push_back(candidates[i]);
    comb(candidates, target-candidates[i], i, ans);
    ans.pop_back();
    comb(candidates, target, i+1, ans);
   }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>ans;
        comb(candidates, target, 0, ans);
        return res;
    }
};