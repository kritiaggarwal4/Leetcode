class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>arr_max(n);
        vector<int>arr_min(n);
           arr_max[0] = nums[0];
           arr_min[n-1] = nums[n-1];
        for(int i=1;i<n;i++){
         arr_max[i] = max(arr_max[i-1], nums[i]);
        }
        for(int j = n-2;j>=0;j--){
            arr_min[j] = min(arr_min[j+1], nums[j]);
        }
        int idx =-1;
        for(int i=0;i<n;i++){
            if(arr_max[i]- arr_min[i]<=k){
               idx =i;
               break;
            }
        }
      return idx;
    }
};