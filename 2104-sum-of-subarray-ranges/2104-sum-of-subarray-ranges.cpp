class Solution {
public:
     vector<int> nse(vector<int>&nums){
        int n = nums.size();
        vector<int>v;
        stack<int>s;
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && nums[s.top()]>=nums[i]){
                s.pop();
            }
            if(s.empty()){
                v.push_back(n);
            }
            else{
                v.push_back(s.top());
                            }
                            s.push(i);
        }
        reverse(v.begin(), v.end());
        return v;
     }
      vector<int> nge(vector<int>&nums){
        int n = nums.size();
        vector<int>v;
        stack<int>s;
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && nums[s.top()]<=nums[i]){
                s.pop();
            }
            if(s.empty()){
                v.push_back(n);
            }
            else{
                v.push_back(s.top());
                            }
                            s.push(i);
        }
        reverse(v.begin(), v.end());
        return v;
     }
      vector<int> psel(vector<int>&nums){
        int n = nums.size();
        vector<int>v;
        stack<int>s;
        for(int i=0;i<n;i++){
            while(!s.empty() && nums[s.top()]>nums[i]){
                s.pop();
            }
            if(s.empty()){
                v.push_back(-1);
            }
            else{
                v.push_back(s.top());
                            }
                            s.push(i);
        }
        return v;
     }
       vector<int> pgel(vector<int>&nums){
        int n = nums.size();
        vector<int>v;
        stack<int>s;
        for(int i=0;i<n;i++){
            while(!s.empty() && nums[s.top()]<nums[i]){
                s.pop();
            }
            if(s.empty()){
                v.push_back(-1);
            }
            else{
                v.push_back(s.top());
                            }
                            s.push(i);
        }
        return v;
     }
     long long subarrayMin(vector<int>&arr){
        vector<int>a = nse(arr);
        vector<int>b = psel(arr);
        long long sum =0;
        for(int i=0;i<arr.size();i++){
            int left = i-b[i];
            int right = a[i]-i;
            sum+=(long long)arr[i]*left*right;
        }
        return sum;
     }
     long long subarrayMax(vector<int>&arr){
        vector<int>a = nge(arr);
        vector<int>b = pgel(arr);
        long long sum = 0;
          for(int i=0;i<arr.size();i++){
            int left = i-b[i];
            int right = a[i]-i;
            sum+=(long long)arr[i]*left*right;
        }
        return sum;
     }
    long long subArrayRanges(vector<int>& nums) {
return subarrayMax(nums)- subarrayMin(nums);
        
    }
};