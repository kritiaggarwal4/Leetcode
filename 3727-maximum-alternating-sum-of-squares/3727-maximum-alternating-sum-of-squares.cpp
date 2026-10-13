class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                nums[i] = abs(nums[i]);
            }
        }
        sort(nums.begin(), nums.end(), greater<int>());
         int evenpos =0;
         int oddpos =0;
         if(n%2==0){
            evenpos = n/2;
            oddpos = n/2;
         }
        else if(n%2!=0){
            evenpos = (n/2)+1;
            oddpos = n/2;
         }
       long long evensum =0;
       for(int i=0;i<evenpos;i++){
        evensum+=1LL*nums[i]*nums[i];
       }
       long long oddsum =0;
       for(int i=evenpos; i<n;i++){
        oddsum+=1LL*nums[i]*nums[i];
       }
       return evensum-oddsum;
    }
};