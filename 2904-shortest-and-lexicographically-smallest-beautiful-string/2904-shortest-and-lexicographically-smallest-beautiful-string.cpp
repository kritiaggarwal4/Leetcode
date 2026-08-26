class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int left =0;
        int right =0;
        string ans = "";
        int n = s.length();
        int countones =0;
        while(right<n){
           if(s[right] == '1'){
            countones++;
          
           }
         while(countones>k){
            if(s[left] == '1')
            countones--;
            left++;
         }
         if(countones ==k){
            while(left<right && s[left]!='1')
            left++;
            string curr = s.substr(left, right-left+1);
            if(ans =="" || ans.size()>curr.size()|| ( curr.length() == ans.length() && curr<ans))
            ans = curr;
         }
           right++;
        }
        return ans;
    }
};