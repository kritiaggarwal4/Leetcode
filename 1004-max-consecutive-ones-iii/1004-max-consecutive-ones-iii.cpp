class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int start =0;
        int end =0;
        int countzero =0;
        int maxi = 0;
        while(end<n){
       
        if(nums[end] ==0 && countzero<=k){
           countzero++;
        }
        while(countzero>k){
            if(nums[start] ==0){
                countzero--;
            }
            start++;
        }
        maxi = max(maxi, end-start+1);
        end++;
        }
      
        return maxi;
    }
};