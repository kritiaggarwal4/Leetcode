class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int>res(code.size(),0);
        long long sum=0;
        int n = code.size();
        int window = abs(k);
        int start =0;
        if(k==0)
        return res;
        if(k>0){
            for(int i=1;i<=k;i++){
                sum+=code[i%n];
            }
            for(int i=0;i<n;i++){
                res[i] = sum;
                sum -=code[(i+1)%n];
                sum+=code[(i+k+1)%n];
            }
            return res;
        }
          if(k<0){
            for(int i=n-window;i<n;i++){
                sum+=code[i%n];
            }
            for(int i=0;i<n;i++){
                res[i%n] = sum;
                sum-=code[(n-window+i)%n];
                sum+=code[i];
            }
            return res;
          }
          return res;
    }
};