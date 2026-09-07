class Solution { //using two pointers approach 
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
       int i=0;
       int j =n-1;
       int maxArea =0;
       while(i<=j){
       int area;
        if(height[i]<height[j]){
         
           area = height[i]*(j-i);
           i++;
        }
        else{
            area = height[j]*(j-i);
            j--;
        }
        maxArea = max(maxArea, area);
       }
       return maxArea;
    }
};
//If height[left] < height[right], then height[left] is the limiting factor.
//If we keep left fixed and move right--, the width decreases, but the height remains the same or gets worse.
//But if we move left++, we might find a taller height, which could compensate for the reduced width.