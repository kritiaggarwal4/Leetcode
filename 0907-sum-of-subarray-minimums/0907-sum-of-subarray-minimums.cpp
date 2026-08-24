class Solution {
public:
const int MOD = 1e9 + 7;
    vector<int> nsr(vector<int>&arr){
        int n = arr.size();
        stack<int>s;
        vector<int>v;
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && arr[i]<arr[s.top()]){
                s.pop();
            }
            if(s.empty())
            v.push_back(n);
            else{
                v.push_back(s.top());
            }
            s.push(i);
        }
        reverse(v.begin(), v.end());
        return v;
    }
     vector<int> nsl(vector<int>&arr){
        int n = arr.size();
        stack<int>s;
        vector<int>v;
        for(int i=0;i<n;i++){
            while(!s.empty() && arr[i]<=arr[s.top()]){
                s.pop();
            }
            if(s.empty())
            v.push_back(-1);
            else{
                v.push_back(s.top());
            }
            s.push(i);
        }
        return v;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int>a = nsr(arr);
        vector<int>b = nsl(arr);
        long long sum =0;
        for(int i=0;i<n;i++){
           sum += (long long)arr[i] * (i - b[i]) * (a[i] - i);
           sum%=MOD;
        }
        return sum;
    }
};