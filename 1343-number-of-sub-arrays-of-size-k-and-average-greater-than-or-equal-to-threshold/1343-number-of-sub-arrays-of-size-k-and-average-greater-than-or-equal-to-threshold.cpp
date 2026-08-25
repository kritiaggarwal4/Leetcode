class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int start =0;
        int sum =0;
        int avg;
        int count =0;
        for(int end =0;end<n;end++){
            sum = sum+arr[end]; 
            //first shrink then check condition
             
            if(end-start+1 ==  k){
                avg = sum/k;
                if(avg>=threshold){
                    count++;
                }
            
                sum = sum-arr[start];
                start++;
            }
            
        }
        return count;
    }
};