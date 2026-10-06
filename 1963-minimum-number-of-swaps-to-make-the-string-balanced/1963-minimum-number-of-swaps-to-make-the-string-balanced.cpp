class Solution {
public:
    int minSwaps(string s) {
        stack<char>st;
        int n = s.length();
        int i=0;
        int swaps =0;
        int balance =0;
        while(i<n){
       if(s[i] == '['){
        balance++;
       }
       else{
        balance--;
       }
       if(balance<0){
        swaps++;
        balance=1;
       }
       i++;
        }
        return swaps;
    }
};