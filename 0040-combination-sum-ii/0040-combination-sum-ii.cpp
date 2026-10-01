class Solution {
public:
vector<vector<int>>res;
void comb(vector<int>&candidates, int target, int start, vector<int>&ans){
    if(target ==0){
        res.push_back(ans);
        return;
    }
  for(int i=start; i< candidates.size(); i++){
    if(i>start && candidates[i] == candidates[i-1])
    continue;
    if(candidates[i]>target){
        break;
    }
    ans.push_back(candidates[i]);
    comb(candidates, target-candidates[i], i+1, ans);
    ans.pop_back();
    }
  }
 vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int>ans;
comb(candidates, target, 0, ans);
return res;
    }
};