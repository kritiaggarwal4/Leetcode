class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      int n = nums.size();
      vector<int>ans;
      deque<int>dq;
      for(int i=0;i<n;i++){
        while(!dq.empty() && dq.front()<=i-k){ //expired indices 
            dq.pop_front();
        }
        while(!dq.empty() && nums[i]>=nums[dq.back()]) //remove the smaller corresponding value 
        dq.pop_back();
        dq.push_back(i);
        if(i>=k-1){
            ans.push_back(nums[dq.front()]);
        }
      }
        return ans;
    }
};


// ########### USING PRIORITY QUEUE TC - O(NLOGN)
//class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//       priority_queue<pair<int, int>>pq;
//       int n = nums.size();
//       int left =0;
//       vector<int>ans;
//       for(int right =0; right<n;right++){
//         pq.push({nums[right], right});
//         if(right-left+1 >k){
//             left++;
//         }
//         while(!pq.empty() && pq.top().second<left){
//             pq.pop();
//         }
//         if(right-left+1 ==k){
//             ans.push_back(pq.top().first);
//         }
//       }
              
//         return ans;
//     }
// };