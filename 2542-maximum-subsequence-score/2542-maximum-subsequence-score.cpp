class Solution {
public:
static bool cmp(pair<int, int>&a, pair<int, int>&b){
    return a.second>b.second;
}
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int, int>>arr(n);
        for(int i=0;i<nums1.size();i++){
             arr[i].first = nums1[i];
             arr[i].second = nums2[i];
        }
        sort(arr.begin(), arr.end(), cmp);
        long long ksum =0;
        priority_queue<int, vector<int>, greater<int>>pq;
        for(int i=0;i<=k-1;i++){
            ksum+=arr[i].first;
            pq.push(arr[i].first);
        }
        long long result = ksum* arr[k-1].second;
        for(int i=k;i<n;i++){
            ksum = (ksum+arr[i].first)-pq.top();
            pq.pop();
            pq.push(arr[i].first);
            long long ans = ksum* arr[i].second;
            result = max(result, ans);
        }
        return result;


    }
};