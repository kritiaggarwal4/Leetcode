class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int>pq;  // maxheap
        vector<int>freq(26, 0);
        vector<int>temp;
        for(char ch: tasks){
            freq[ch- 'A']++;
        }
        for(int f: freq){
            if(f!=0)
            pq.push(f);
        }
        int count =0;
        while(!pq. empty()){
            int value;
            for(int i=0;i<=n;i++){
               
                if(pq.empty()){
                    count+=1;
                }
                else{
                     value = pq.top();
                     pq.pop();
                value = value-1;
                count+=1;
                if(value!=0)
                temp.push_back(value);
                }
                  if(pq.empty() && temp.empty()) //to not consider last idle value directly break
                    break;
            }
          for(int x:temp){
            pq.push(x);
          }
          temp.clear();
        }
    return count;
    }
};