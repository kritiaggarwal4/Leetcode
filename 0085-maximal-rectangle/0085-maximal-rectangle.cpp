class Solution {
public:
  vector<int> nsr(vector<int>&heights){
        stack<int>s;
        vector<int>v;
        int n = heights.size();
        for(int i=n-1;i>=0;i--){
        while(!s.empty() && heights[s.top()]>=heights[i]){
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
     vector<int>nsl(vector<int>&heights){
          stack<int>s;
        vector<int>v;
        int n = heights.size();
        for(int i=0;i<n;i++){
        while(!s.empty() && heights[s.top()]>=heights[i]){
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
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>a = nsr(heights);
        vector<int>b = nsl(heights);
        int maxi = INT_MIN;
        for(int i=0;i<heights.size();i++){
           int idx = (a[i]-b[i]-1);
           int width = idx*heights[i];
              maxi = max(maxi, width);
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
   
      int n = matrix.size();
    int m = matrix[0].size();

    vector<int> v(m, 0);
    int maxi = 0;

    for(int i = 0; i < n; i++) {

        for(int j = 0; j < m; j++) {

            if(matrix[i][j] == '1')
                v[j]++;
            else
                v[j] = 0;
        }

        maxi = max(maxi, largestRectangleArea(v));
    }

    return maxi;
    }
};