class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int n = g.size();
        int count =0;
        int i=0;
        int j =0;
        int m = s.size();
        while(i<n && j<m){
            if(s[j]>=g[i]){
            count++;
            i++;
            j++;
            }
            else if(s[j]<g[i]){
             j++;
            }
        }
        return count;
    }
};