class Solution {
public:
vector<int>ngel(vector<int>&nums2){
    vector<int>nge(nums2.size());
    stack<int>st;
    int n = nums2.size();
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && st.top()<=nums2[i]){
            st.pop();
        }
        if(st.empty()){
         nge[i] =-1;
        }
        else{
            nge[i] = st.top();
        }
        st.push(nums2[i]);
    }
    return nge;
    }

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        int n = nums2.size();
        unordered_map<int, int>mp;
        vector<int>nge = ngel(nums2);
        for(int i=0;i<nums2.size();i++){
         mp[nums2[i]] = nge[i];
        }
        vector<int>ans(nums1.size());
        for(int i=0;i<nums1.size();i++){
          ans[i] = mp[nums1[i]];
        }
return ans;
        
    }
};