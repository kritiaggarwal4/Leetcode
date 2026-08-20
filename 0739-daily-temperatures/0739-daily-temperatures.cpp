class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
       int n = temperatures.size();
       stack<pair<int, int>>s;
       vector<int>v(n,-1);
       for(int i=n-1;i>=0;i--){
        while(!s.empty() && s.top().first<=temperatures[i]){
            s.pop();
        }
        if(s.empty()){
             v[i] = 0;
        }
        else{
            v[i] = s.top().second - i;
        }
        s.push({temperatures[i], i});
       }
       return v;
    }
};