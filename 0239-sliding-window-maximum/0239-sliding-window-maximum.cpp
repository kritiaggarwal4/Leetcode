class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      priority_queue<pair<int, int>>pq;
      int n = nums.size();
      int left =0;
      vector<int>ans;
      for(int right =0; right<n;right++){
        pq.push({nums[right], right});
        if(right-left+1 >k){
            left++;
        }
        while(!pq.empty() && pq.top().second<left){
            pq.pop();
        }
        if(right-left+1 ==k){
            ans.push_back(pq.top().first);
        }
      }
              
        return ans;
    }
};