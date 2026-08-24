class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>v;
        stack<int>s;
        int n = asteroids.size();
      
        for(int i=0;i<n;i++){
              bool  destroyed = false;
           while(!s.empty() && asteroids[i]<0 && s.top()>0){
            if(abs(asteroids[i])>s.top()){
                s.pop();
                }
                else if(abs(asteroids[i])==s.top()){
                   s.pop();
                   destroyed = true;
                   break;
                }
                else{
                    destroyed = true;
                    break;
                }
           }
           if(!destroyed){
            s.push(asteroids[i]);
           }
         
        }
        while(!s.empty()){
            v.push_back(s.top());
            s.pop();
        }
        reverse(v.begin(), v.end());
        return v;
    }
};