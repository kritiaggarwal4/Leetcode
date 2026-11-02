class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int num;
        if(n%2 ==0){
        num = n/2;
        }
        else{
            num= (n/2);
        }
        int moves =0;
        for(int i=0;i<n;i++){
            moves = moves+(abs(nums[i] - nums[num]));
        }
        return moves;
    }
};