class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";
        int i=0;
        while(i<num){
            int curr = min(sum, 9);
            ans+=to_string(curr);
            sum-=curr;
            i++;
        }
        if(sum !=0){
            return "";
        }
   return ans;
    }
};